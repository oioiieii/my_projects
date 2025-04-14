using CommunityToolkit.Mvvm.Input;
using CommunityToolkit.Mvvm.ComponentModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Diagnostics;
using System.Security.Cryptography;
using System.Threading;
using System.Collections.ObjectModel;

namespace AsyncFileDownloader.ViewModels
{
    public partial class MainWinodwViewModel: ObservableObject
    {
        public enum StatusFile
        {
            Waiting = 0,
            Loading = 1,
            Completed = 2
        }

        public partial class File : ObservableObject
        {
            [ObservableProperty]
            public int _numFile = 0;

            [ObservableProperty]
            private StatusFile _statusFile = StatusFile.Waiting;
        }

        public ObservableCollection<File> Files { get; set; } = [];


        [ObservableProperty]
        private double _progressValue = 0;

        [ObservableProperty]
        private string _textLog = "";

        [ObservableProperty]
        private int _countFiles = 5;

        private object locker = new object();

        private SemaphoreSlim semaphoreSlim = new (5, 5);

        [RelayCommand]
        public async Task StartDownloading()
        {
            try
            {
                TextLog = "";
                ProgressValue = 0;
                Files.Clear();
                TextLog += $"Начинается скачивание {CountFiles} файлов: \n";

                var stopwatch = Stopwatch.StartNew();
                await Task.WhenAll([..Enumerable.Range(0, CountFiles).Select(async i =>
                {
                    Files.Add(new File{ NumFile = i + 1, StatusFile = StatusFile.Waiting});
                    await semaphoreSlim.WaitAsync();
                    try{
                        await DownloadFiles(i);
                    }
                    finally{
                        semaphoreSlim.Release();
                    }
                })]);

                stopwatch.Stop();

                TextLog += $"Cкачивание {CountFiles} файлов завершено успешно! \n";
                TextLog += $"Для этого потребовалось времени: {stopwatch.Elapsed.ToString("mm\\:ss")}. \n";
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Произошла непредвиденная ошибка: {ex.Message}", "Ошибка!", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }

        async Task DownloadFiles(int numFile)
        {
            Files[numFile].StatusFile = StatusFile.Loading;
            for (int i = 0; i < 20; i++)
            {
                await Task.Delay(200);
                lock (locker)
                {
                    ProgressValue += 5.0 / CountFiles;
                }
            }
            Files[numFile].StatusFile = StatusFile.Completed;
        }
    }
}
