namespace LibraryProject.Infrastructure.Entities
{
    public class Library
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public string Address { get; set; } = string.Empty;

        public List<Book> Books { get; set; } = [];

        public List<User> Users { get; set; } = [];
    }
}
