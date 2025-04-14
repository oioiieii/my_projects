using LibraryProject.Infrastructure.Database;
using LibraryProject.Infrastructure.Entities;
using LibraryProject.Infrastructure.Repositories.Interfaces;
using Microsoft.EntityFrameworkCore;

namespace LibraryProject.Infrastructure.Repositories
{
    public class BookRepository : IBookRepository
    {
        private readonly LibraryProjectDbContext _context;

        public BookRepository(LibraryProjectDbContext context)
        {
            _context = context;   
        }

        public async Task AddAsync(Book book)
        {
            _context.Books.Add(book);
            await _context.SaveChangesAsync();
        }

        public async Task RentExecuteAsync(Guid bookId, Guid userId)
        {
            await _context.Books
                .Where(b => b.Id == bookId)
                .ExecuteUpdateAsync(b => b
                    .SetProperty(b => b.UserId, userId));
        }

        public async Task<List<Book>> GetAllAsync()
        {
            return await _context.Books.ToListAsync();
        }
    }
}
