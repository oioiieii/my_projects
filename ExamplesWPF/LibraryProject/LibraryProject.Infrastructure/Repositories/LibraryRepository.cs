using LibraryProject.Infrastructure.Database;
using LibraryProject.Infrastructure.Entities;
using LibraryProject.Infrastructure.Repositories.Interfaces;
using Microsoft.EntityFrameworkCore;

namespace LibraryProject.Infrastructure.Repositories
{
    public class LibraryRepository : ILibraryRepository
    {
        private readonly LibraryProjectDbContext _context;

        public LibraryRepository(LibraryProjectDbContext context)
        {
            _context = context;   
        }

        public async Task AddAsync(Library lib)
        {
            _context.Libraries.Add(lib);
            await _context.SaveChangesAsync();
        }

        public async Task<List<Library>> GetAllAsync()
        {
            return await _context.Libraries.ToListAsync();
        }
    }
}
