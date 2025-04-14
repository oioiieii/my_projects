using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using LibraryProject.Infrastructure.Entities;
using LibraryProject.Infrastructure.Repositories;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace LibraryProject.WPF.ViewModels
{
    public partial class MainWindowViewModel: ObservableObject
    {
        private readonly BookRepository _bookRepo;
        private readonly LibraryRepository _libraryRepo;
        private readonly UserRepository _userRepo;

        public ObservableCollection<Book> Books { get; set; } = [];
        public ObservableCollection<Library> Libraries { get; set; } = [];

        private Book[] _allBooks = [];

        [ObservableProperty]
        private string _userNameTextBox = string.Empty;
        
        [ObservableProperty]
        private StringBuilder _logText = new ();

        private User? _user;
        public MainWindowViewModel(BookRepository bookRepo, LibraryRepository libraryRepo, UserRepository userRepo)
        {
            _bookRepo = bookRepo;
            _libraryRepo = libraryRepo;
            _userRepo = userRepo;
        }

        [ObservableProperty]
        private bool _userIdentified = false;

        private void HeavyWork()
        {
            // Например, находим все простые числа до 5 миллионов
            List<int> primes = new();

            for (int i = 2; i < 5_000_000; i++)
            {
                bool isPrime = true;

                for (int j = 2; j * j <= i; j++)
                {
                    if (i % j == 0)
                    {
                        isPrime = false;
                        break;
                    }
                }

                if (isPrime)
                    primes.Add(i);
            }

            Console.WriteLine($"Найдено {primes.Count} простых чисел.");
        }

        [RelayCommand]
        public async Task ConfirmUser()
        {
            try
            {
                //string convertFIO = await Task.Run(() => ConvertFIO(UserNameTextBox));
                string convertFIO = ConvertFIO(UserNameTextBox);
                _user = await _userRepo.FindUser(convertFIO);

                if (_user == null)
                {
                    //Такого пользователя еще нет, регестрируем
                    var result = MessageBox.Show("Пользователь с таким ФИО не был найден. Вы желаете зарегестрироваться?", "Информация", MessageBoxButton.YesNo, MessageBoxImage.Information);
                    if (result == MessageBoxResult.Yes)
                    {
                        _user = new User()
                        {
                            Id = Guid.NewGuid(),
                            Name = convertFIO,
                        };
                        await _userRepo.AddAsync(_user);
                        LogText.AppendLine("Вы были успешно зарегестрированы.");
                        OnPropertyChanged(nameof(LogText));
                    }
                    else return;
                }
                else
                {
                    //Авторизация прошла успешно
                    LogText.AppendLine("Вы были успешно авторизованы.");
                    OnPropertyChanged(nameof(LogText));
                }
                UserNameTextBox = _user.Name;

                //Находим все Библиотеки и Книги
                Libraries.Clear();
                foreach (var lb in await _libraryRepo.GetAllAsync())
                {
                    Libraries.Add(lb);
                }
                _allBooks = [.. await _bookRepo.GetAllAsync()];

                UserIdentified = true;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }

        [ObservableProperty]
        private Library? selectedLibrary;

        partial void OnSelectedLibraryChanged(Library? value)
        {
            if (value != null)
            {
                Books.Clear();
                foreach (var book in _allBooks)
                {
                    if (book.Library!.Id == SelectedLibrary!.Id && book.UserId == null) Books.Add(book);
                }
            }
        }

        [ObservableProperty]
        private Book? selectedBook;

        [RelayCommand]
        public async Task RentBook()
        {
            try
            {
                if (SelectedLibrary == null & SelectedBook == null) 
                    throw new Exception("Вы не выбрали необходимые данные для бронирования!");
                await _bookRepo.RentExecuteAsync(SelectedBook!.Id, _user!.Id);
                
                LogText.AppendLine($"Вы успешно забронировали книгу под названием '{SelectedBook.Title}'." +
                    $"\nВы можете её забрать в библиотеке '{SelectedLibrary!.Name}'," +
                    $"\nрасположенной по адресу '{SelectedLibrary!.Address}'.");

                _user.Books.Add(SelectedBook);
                Books.Remove(SelectedBook);
                SelectedBook = null;
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message, "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error);
                LogText.AppendLine("Что-то пошло не так :(");
            }
            finally
            {
                OnPropertyChanged(nameof(LogText));
            }

        } 

        private string ConvertFIO(string text)
        {
            var words = text.Split([',', ' ', '.'], StringSplitOptions.RemoveEmptyEntries)
                .Select(w => w.Trim()).ToList();
            if (words.Count < 3)
            {
                throw new Exception("Введите ФИО полностью, в случае отсутствия Отчества поставьте '-'.");
            }
            words[1] = words[1][0].ToString().ToUpper() + ".";
            words[2] = words[2][0].ToString().ToUpper() + ".";
            string result = string.Join(" ", words.Take(3));
            return result;
        } 
    }
}
