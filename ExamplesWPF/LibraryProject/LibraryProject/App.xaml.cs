using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.Configuration;
using System.IO;
using System.Windows;
using System;
using LibraryProject.Infrastructure.Database;
using LibraryProject.Infrastructure.Repositories;
using LibraryProject.WPF.Views;
using Microsoft.EntityFrameworkCore;
using LibraryProject.WPF.ViewModels;

namespace LibraryProject;

/// <summary>
/// Interaction logic for App.xaml
/// </summary>
public partial class App : Application
{
    private IHost? _host;

    public App()
    {
        _host = Host.CreateDefaultBuilder()
            .ConfigureAppConfiguration(config =>
            {
                config.AddJsonFile("appsettings.json", optional: false, reloadOnChange: true);
            })
            .ConfigureServices((context, services) =>
            {
                // Подключаем DbContext
                string connectionString = context.Configuration.GetConnectionString("DefaultConnection");

                services.AddDbContext<LibraryProjectDbContext>(options =>
                    options.UseNpgsql(connectionString));

                // Регистрируем репозитории
                services.AddScoped<BookRepository>();
                services.AddScoped<UserRepository>();
                services.AddScoped<LibraryRepository>();

                // Регистрируем ViewModels
                services.AddScoped<MainWindowViewModel>();

                // Регистрируем окна
                services.AddSingleton<MainWindow>();
            })
            .Build();
    }

    protected override async void OnStartup(StartupEventArgs e)
    {
        await _host!.StartAsync();

        // Получаем окно и показываем
        var mainWindow = _host.Services.GetRequiredService<MainWindow>();
        mainWindow.Show();

        base.OnStartup(e);
    }

    protected override async void OnExit(ExitEventArgs e)
    {
        await _host!.StopAsync();
        _host.Dispose();
        base.OnExit(e);
    }
}

