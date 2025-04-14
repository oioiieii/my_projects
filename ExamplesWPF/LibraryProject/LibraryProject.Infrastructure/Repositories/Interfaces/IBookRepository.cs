using LibraryProject.Infrastructure.Entities;

namespace LibraryProject.Infrastructure.Repositories.Interfaces
{
    public interface IBookRepository
    {
        Task<List<Book>> GetAllAsync();
        Task RentExecuteAsync(Guid bookId, Guid userId);
        Task AddAsync(Book bk);
    }
}
