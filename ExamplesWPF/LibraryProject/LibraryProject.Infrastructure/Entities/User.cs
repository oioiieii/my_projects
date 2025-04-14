namespace LibraryProject.Infrastructure.Entities
{
    public class User {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;

        public List<Book> Books { get; set; } = [];

        public List<Library> Libraries { get; set; } = [];
    }
}
