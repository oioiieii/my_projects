using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Microsoft.Win32;
using System.IO;
using System.Text;
using System.Windows.Input;

namespace TextAnalyzerMini.ViewModels
{
    partial class MainWindowViewModel: ObservableObject
    {

        public MainWindowViewModel()
        {
            Calculate();
        }

        [ObservableProperty]
        private string _filePath = Path.Combine(Directory.GetCurrentDirectory(), "sample.txt");

        [ObservableProperty]
        private string _textInput = "";

        [ObservableProperty]
        private string _textOutput = "";

        void Calculate()
        {
            try
            {
                _textInput = File.ReadAllText(_filePath);

                var topWords = _textInput
                    .Trim()
                    .Split([' ', ',', '.', '!', '?', ';', '-', '\n', '(', ')'], StringSplitOptions.RemoveEmptyEntries)
                    .Select(word => word.ToLower())
                    .Where(word => word.Length >= 4)
                    .OrderBy(word => word)
                    .GroupBy(word => word)
                    .OrderByDescending(word => word.Count())
                    .Take(5);

                StringBuilder sb = new StringBuilder();
                foreach (var word in topWords)
                {
                    sb.AppendLine($"Слово: {word.Key}, Счетчик: {word.Count()}");
                }
                _textOutput = sb.ToString();
            }
            catch(Exception ex)
            {
                _textInput = $"Error: {ex.Message}";
            }
        }

        [RelayCommand]
        private void OpenFileDialog()
        {
            var dialog = new OpenFileDialog
            {
                Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*"
            };

            if (dialog.ShowDialog() == true)
            {
                _filePath = dialog.FileName;
                Calculate();
            }
        }
    }
}
