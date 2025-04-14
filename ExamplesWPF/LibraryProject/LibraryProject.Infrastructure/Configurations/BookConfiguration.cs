using LibraryProject.Infrastructure.Entities;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Metadata.Builders;

namespace LibraryProject.Infrastructure.Configurations
{
    public class BookConfiguration : IEntityTypeConfiguration<Book>
    {
        public void Configure(EntityTypeBuilder<Book> builder)
        {
            builder.HasKey(b => b.Id);

            builder
                .HasOne(b => b.Library)
                .WithMany(l => l.Books);

            builder
                .HasOne(b => b.User)
                .WithMany(u => u.Books)
                .IsRequired(false);
        }
    }
}
