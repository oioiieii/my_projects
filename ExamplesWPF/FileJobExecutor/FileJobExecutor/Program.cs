using System;
using System.Diagnostics;
using System.IO;
using System.Text;

//Вспомнил работу с консолькой
/*string input = Console.ReadLine();
Console.WriteLine("Вы ввели: " + input);

Console.WriteLine("\n\n Продолжаем... \n");
*/

//БЫСТРЫЙ СПОСОБ ЧТЕНИЯ/ЗАПИСИ (File.ReadAllText/File.WriteAllText)
/*string path = "example.txt";
Console.WriteLine($"Вот содержимое файла {path} :");

string[] text = File.ReadAllLines(path);

foreach (string line in text)
{
    Console.WriteLine(line);
}

File.WriteAllText("newTxt.txt", "Hello, World!");
*/

//ПОСТРОЧНАЯ РАБОТА (streamReader/StreamWriter)
/*string path = "example.txt";

//string text = File.ReadAllText(path);
using (StreamWriter writer =  new StreamWriter(path))
{
    //writer.WriteLine(text);
    writer.WriteLine("Первая строка");
    writer.WriteLine("Вторая строка");
}

using (StreamReader reader = new StreamReader(path))
{
    string line;
    while ((line = reader.ReadLine()) != null)
    {
        Console.WriteLine(line);
    }
}

*/

//Мини задача 1:
/*string path = "example.txt";

using(StreamReader reader = new StreamReader(path))
{
    string line;
    
    while ((line = reader.ReadLine()) != null)
    {
        if (line.Length > 35)
        {
            Console.WriteLine(line);
        }
    }
}*/

//StringBuilder
/*StringBuilder sb = new StringBuilder();
sb.Append("Hello");
sb.Append(", ");
sb.Append("World!");
string result = sb.ToString();

Console.WriteLine(result);*/

/*//ДЕМОНСТРАЦИЯ ТО ЧТО ПРИВОДИТ К ЗАВИСАНИЮ (Надо избегать плюсования строк)
var sb = new StringBuilder();
for (int i = 0; i < 10000000; i++)
{
    sb.Append(i);
}
string result = sb.ToString(sb);
Console.ReadLine();

string result1 = "";
for (int i = 0; i < 10000; i++)
{
    result1 += i.ToString();
}
Console.ReadLine();
*/


//Мини задача 2:
/*string[] words = { "C#", "это", "круто", "!" };
StringBuilder sb = new StringBuilder();
foreach (var word in words)
{
    sb.Append(word + " ");
}
Console.WriteLine(sb.ToString());*/


//LINQ
/*
int[] numbers = { 1, 2, 3, 4, 5 };

var evenNumbers = numbers.GroupBy(n => n % 2);

foreach (var group in evenNumbers)
{
    Console.WriteLine($" {group.Key} : ");
    foreach (var number in group)
    {
        Console.WriteLine(number);
    }
}
*/
/*var numbers = new List<int> { 2, 4, 6};

bool anyOdd = numbers.Any(n => n % 2 != 0); // false
bool allEven = numbers.All(n => n % 2 == 0); // true

Console.WriteLine($"anyOdd: {anyOdd}");
*/
/*string text = "C# это крутой современный язык программирования";
var words = text.Split(' ')
                .Where(w => w.Length > 5)
                .Select(w => w.ToUpper());

foreach (var word in words)
    Console.WriteLine(word);*/


//Мини задача 3:
//Создай список строк (например, имена пользователей), отфильтруй имена длиной > 4 символов, отсортируй их по алфавиту и выведи в верхнем регистре.
/*
List<string> names = new List<string>
{
    "Charlie",
    "David",
    "Alice",
    "Bob",
    "Eve"
};

var outputNames = names.Where(name => name.Length > 4).OrderBy(name => name).Select(name => name.ToUpper()).ToList();
foreach (var name in outputNames)
{
    Console.WriteLine(name);
}
*/