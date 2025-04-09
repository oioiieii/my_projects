#include <iostream>
#include "classes.h"

#include <thread>  
#include <chrono>  


int main()
{
    setlocale(LC_ALL, "ru");
    City town1("Ростов", 10000, 500);
    City town2("Севастополь", 10000, 500);
    MegaCity town3("Москва", 1000000, 10000);
    MegaCity town4("Санкт-Петербург",  1000000, 10000);
    City town5("Керчь",  10000, 500);

    City* citiesReg1[] = { &town1, &town2, &town3, &town4, &town5};
    Region reg1("Главный регион", citiesReg1, 5);

    Person human1("Иванов И.И.", 19);
    
    IMutable* mutableObjects[] = { &town1, &town2, &town3, &town4, &town5, &human1 };
    int counter = 2024;
    while (true) {
        cout << " - - - - - - -\nНовый "<< counter << " год\n - - - - - - -\n";
        for (int i = 0; i < 6; ++i) {
            mutableObjects[i]->live();
        }
        cout << " - - - - - - -\n";
        counter++;

        if ((counter - 2024) % 10 == 0) {
            cout << "\n\nСВОДКА НЕКОТОРЫХ НАСЕЛЕННЫХ ПУНКТОВ\n\n";
            reg1.output_name();
            reg1.output_population();
            reg1.output_area();

            cout << endl;

            town1.output_name();
            town1.output_population();
            town1.output_area();

            cout << endl;

            town3.output_name();
            town3.output_population();
            town3.output_area();

            cin.get();
            system("cls");
            cout << "НОВОЕ ДЕСЯТИЛЕТИЕ\n";
        }
        //Пауза на 5 секунд
        this_thread::sleep_for(chrono::seconds(2));
    }
}