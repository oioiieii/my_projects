using LibraryProject.Infrastructure.Configurations;
using LibraryProject.Infrastructure.Entities;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;

namespace LibraryProject.Infrastructure.Database
{
    public class LibraryProjectDbContext(DbContextOptions<LibraryProjectDbContext> options) : DbContext(options)
    {
        public DbSet<Book> Books { get; set; }
        public DbSet<Library> Libraries { get; set; }
        public DbSet<User> Users { get; set; }
                     

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            //Сюда писать буду свойства конфигурации
            modelBuilder.ApplyConfiguration(new BookConfiguration());
            modelBuilder.ApplyConfiguration(new UserConfiguration());
            modelBuilder.ApplyConfiguration(new LibraryConfiguration());

            base.OnModelCreating(modelBuilder);
        }
    }
}
