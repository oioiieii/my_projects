using LibraryProject.Infrastructure.Database;
using LibraryProject.Infrastructure.Entities;
using LibraryProject.Infrastructure.Repositories.Interfaces;
using Microsoft.EntityFrameworkCore;

namespace LibraryProject.Infrastructure.Repositories
{
    public class UserRepository : IUserRepository
    {
        private readonly LibraryProjectDbContext _context;

        public UserRepository(LibraryProjectDbContext context)
        {
            _context = context;   
        }

        public async Task AddAsync(User User)
        {
            _context.Users.Add(User);
            await _context.SaveChangesAsync();
        }

        public async Task<User?> FindUser(string name)
        {
            return await _context.Users.FirstOrDefaultAsync(u => u.Name == name);
        }

        public async Task<List<User>> GetAllAsync()
        {
            return await _context.Users.ToListAsync();
        }
    }
}
