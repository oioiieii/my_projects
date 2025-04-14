using LibraryProject.Infrastructure.Entities;

namespace LibraryProject.Infrastructure.Repositories.Interfaces
{
    public interface IUserRepository
    {
        Task<List<User>> GetAllAsync();
        Task AddAsync(User usr);
    }
}
