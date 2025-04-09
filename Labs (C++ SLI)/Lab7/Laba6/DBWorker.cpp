#include "pch.h"
#include "DBWorker.h"

#include <string>
#include <locale>
#include <codecvt>
#include <msclr/marshal_cppstd.h>
#include <array> 


std::string Laba6::DBWorker::convert_to_string(System::String^ txt_input)
{
    if (txt_input == nullptr) return "";
    msclr::interop::marshal_context context;

    // Convert System::String^ to std::wstring
    std::wstring wstr = context.marshal_as<std::wstring>(txt_input);

    // Convert std::wstring to UTF-8 encoded std::string
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;
    std::string utf8NativeString = convert.to_bytes(wstr);

    return utf8NativeString;
}

System::String^ Laba6::DBWorker::FixEncoding(const std::string& str)
{
    char utf8[100];
    wchar_t wstr[100];
    char s1251[100];

    // Копируем строку UTF-8 в массив utf8
    strcpy_s(utf8, sizeof(utf8), str.c_str());

    // Преобразуем UTF-8 в Unicode (wchar_t)
    int wstrLength = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, 100);

    // Убедимся, что преобразование успешно завершено
    if (wstrLength == 0) {
        throw gcnew System::Exception("Ошибка преобразования UTF-8 в Unicode");
    }

    // Преобразуем Unicode в CP1251
    int s1251Length = WideCharToMultiByte(1251, 0, wstr, wstrLength, s1251, 100, NULL, NULL);

    // Убедимся, что преобразование успешно завершено
    if (s1251Length == 0) {
        throw gcnew System::Exception("Ошибка преобразования Unicode в CP1251");
    }

    // Добавляем нулевой символ конца строки
    s1251[s1251Length] = '\0';

    return gcnew System::String(s1251);
}