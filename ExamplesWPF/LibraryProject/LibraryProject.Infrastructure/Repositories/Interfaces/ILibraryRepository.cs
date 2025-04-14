using LibraryProject.Infrastructure.Entities;

namespace LibraryProject.Infrastructure.Repositories.Interfaces
{
    public interface ILibraryRepository
    {
        Task<List<Library>> GetAllAsync();
        Task AddAsync(Library lib);
    }
}
