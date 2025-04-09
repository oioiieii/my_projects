#include "pch.h"
#include "organization.h"

int main(array<System::String^>^ args) {
    gasCompany^ gasCompany1 = gcnew gasCompany("ООО 'Нефтегаз премиум'", "8212566660", 100000000, 8000, 9200, 1000, 800);
    insuranceCompany^ insuranceCompany1 = gcnew insuranceCompany("ООО 'Страха нет'", "8899123415", 2000000, 300, 5, 6, 10000, 200000);
    factory^ factory1 = gcnew factory("Мегатрон", "2232346763", 1000000, 1000, 450, 120);
    bool flag = true;
    int dayCounter = 1;
    while (flag) {
        Console::WriteLine("\n\n----------------------- \nДень {0}:\n----------------------- \n", dayCounter);
        gasCompany1->Extraction();
        insuranceCompany1->Service();
        factory1->Production();

        if (dayCounter % 7 == 0) {
            Console::WriteLine("\n\n----------------------- \nЕженедельная сводка:\n----------------------- \n");
            gasCompany1->Export();
            insuranceCompany1->CollectingPayment();

            gasCompany1->getInfo();
            insuranceCompany1->getInfo();
            factory1->getInfo();
            System::Threading::Thread::Sleep(10000);
        }
        dayCounter++;
        System::Threading::Thread::Sleep(5000);
    }
    return 0;
}