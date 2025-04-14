using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Design;
using Microsoft.Extensions.Configuration;

namespace LibraryProject.Infrastructure.Database;

public class LibraryProjectDbContextFactory : IDesignTimeDbContextFactory<LibraryProjectDbContext>
{
    public LibraryProjectDbContext CreateDbContext(string[] args)
    {
        // Путь к конфигу стартап-проекта (WPF)
        var configuration = new ConfigurationBuilder()
            .SetBasePath(Path.Combine(Directory.GetCurrentDirectory(), "../LibraryProject"))
            .AddJsonFile("appsettings.json")
            .Build();

        var optionsBuilder = new DbContextOptionsBuilder<LibraryProjectDbContext>();
        var connectionString = configuration.GetConnectionString("DefaultConnection");

        optionsBuilder.UseNpgsql(connectionString);

        return new LibraryProjectDbContext(optionsBuilder.Options);
    }
}
