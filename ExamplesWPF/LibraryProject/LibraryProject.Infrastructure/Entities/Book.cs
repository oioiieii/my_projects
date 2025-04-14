namespace LibraryProject.Infrastructure.Entities
{
    public class Book
    {
        public Guid Id { get; set; }
        public string Title { get; set; } = string.Empty;

        public Guid? UserId { get; set; }
        public User? User { get; set; }

        public Guid LibraryId { get; set; }
        public Library? Library { get; set; }
    }
}
