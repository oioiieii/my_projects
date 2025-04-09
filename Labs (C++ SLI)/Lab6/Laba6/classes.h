#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>


    using namespace System::Collections;
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections::Generic;

    enum class TableType
    {
        Brands,
        Manufacturers,
        Owners,
        Cars,
        Registrations
    };

    namespace Laba6 {

    // Класс производителя
    ref class Manufacturer {
    public:
        static int counter = 0;
        static ArrayList^ manufacturers = gcnew ArrayList();
        static BindingList<Manufacturer^>^ manufacturersBL = gcnew BindingList<Manufacturer^>();

        property Manufacturer^ This;
        property int ManufacturerCode;
        property System::String^ Name;
        property System::String^ Address;

        Manufacturer() {
            This = this;
            ManufacturerCode = -1;
            Name = nullptr;
            Address = nullptr;
        }

        Manufacturer(System::String^ name, System::String^ address) {
            This = this;
            ManufacturerCode = counter++;
            Name = name;
            Address = address;
            manufacturersBL->Add(this);
        }

        Manufacturer(int code, System::String^ name, System::String^ address) {
            This = this;
            ManufacturerCode = code;
            if (counter <= code) counter = code + 1;
            Name = name;
            Address = address;
            manufacturersBL->Add(this);
        }
        Manufacturer(Manufacturer^ manufacturer) {
            This = this;
            ManufacturerCode = manufacturer->ManufacturerCode;
            if (counter <= manufacturer->ManufacturerCode) counter = manufacturer->ManufacturerCode + 1;
            Name = manufacturer->Name;
            Address = manufacturer->Address;
            manufacturersBL->Add(this);
        }
    };
    

    // Класс марки
    ref class Brand {
    public:
        static int counter = 0;
        static ArrayList^ brands = gcnew ArrayList();

        property Brand^ This;
        property int brandCode;
        property System::String^ name;
        property Manufacturer^ manufacturer;

        Brand() {
            This = this;
            brandCode = -1;
            name = nullptr;
            manufacturer = nullptr;
        }

        Brand(System::String^ name_, Manufacturer^ manufacturer_) {
            This = this;
            brandCode = counter++;
            name = name_;
            manufacturer = manufacturer_;
        }

        Brand(int code_, System::String^ name_, Manufacturer^ manufacturer_) {
            This = this;
            brandCode = code_;
            if (counter <= code_) counter = code_ + 1;
            name = name_;
            manufacturer = manufacturer_;
        }

        Brand(Brand^ brand, List<Manufacturer^>^ array) {
            This = this;
            brandCode = brand->brandCode;
            name = brand->name;

            for each (Manufacturer ^ var in array) {
                if (var->ManufacturerCode == brand->manufacturer->ManufacturerCode) {
                    manufacturer = var;
                    break;
                }
            }
        }
    };

    
    // Класс владельца
    public ref class Owner {
    public:
        static int counter = 0;
        static ArrayList^ owners = gcnew ArrayList();

        property Owner^ This;
        property int ownerCode;
        property System::String^ fullName;
        property System::String^ address;

        Owner() {
            This = this;
            ownerCode = -1;
            this->fullName = nullptr;
            this->address = nullptr;
        }

        Owner(System::String^ fullName, System::String^ address) {
            This = this;
            ownerCode = counter++;
            this->fullName = fullName;
            this->address = address;
        }

        Owner(int code, System::String^ fullName, System::String^ address) {
            This = this;
            ownerCode = code;
            if (counter <= code) counter = code + 1;
            this->fullName = fullName;
            this->address = address;
        }

        Owner(Owner^ owner) {
            This = this;
            ownerCode = owner->ownerCode;
            fullName = owner->fullName;
            address = owner->address;
        }
    };

    // Класс автомобиля
    public ref class Car {
    public:
        static int counter = 0;
        static ArrayList^ cars = gcnew ArrayList();

        property Car^ This;
        property int carCode;
        property Brand^ brand;
        property System::String^ chassisNumber;
        property System::String^ engineNumber;

        Car() {
            This = this;
            carCode = -1;
            this->brand = nullptr;
            this->chassisNumber = nullptr;
            this->engineNumber = nullptr;
        }

        Car(Brand^ brand_, System::String^ chassisNumber, System::String^ engineNumber) {
            This = this;
            carCode = counter++;
            this->brand = brand_;
            this->chassisNumber = chassisNumber;
            this->engineNumber = engineNumber;
        }

        Car(int code, Brand^ brand_, System::String^ chassisNumber, System::String^ engineNumber) {
            This = this;
            carCode = code;
            if (counter <= code) counter = code + 1;
            this->brand = brand_;
            this->chassisNumber = chassisNumber;
            this->engineNumber = engineNumber;
        }

        Car(Car^ car, List<Brand^>^ array) {
            This = this;
            carCode = car->carCode;
            chassisNumber = car->chassisNumber;
            engineNumber = car->engineNumber;

            for each (Brand ^ var in array) {
                if (var->brandCode == car->brand->brandCode) {
                    brand = var;
                    break;
                }
            }
        }
    };

    // Класс регистрации
    public ref class Registration {
    public:
        static int counter = 0;
        static ArrayList^ registrations = gcnew ArrayList();

        property Registration^ This;
        property int registrationCode;
        property Owner^ owner;
        property Car^ car;
        property String^ date;

        Registration() {
            This = this;
            registrationCode = -1;
            owner = nullptr;
            car = nullptr;
            date = nullptr;
        }

        Registration(Owner^ owner_, Car^ car_, String^ date) {
            This = this;
            registrationCode = counter++;
            this->owner = owner_;
            this->car = car_;
            this->date = date;
        }

        Registration(int code, Owner^ owner_, Car^ car_, String^ date) {
            This = this;
            registrationCode = code;
            if (counter <= code) counter = code + 1;
            this->owner = owner_;
            this->car = car_;
            this->date = date;
        }

        Registration(Registration^ registration, List<Owner^>^ ownerArray, List<Car^>^ carArray) {
            This = this;
            registrationCode = registration->registrationCode;
            date = registration->date;

            for each (Owner ^ var in ownerArray) {
                if (var->ownerCode == registration->owner->ownerCode) {
                    owner = var;
                    break;
                }
            }

            for each (Car ^ var in carArray) {
                if (var->carCode == registration->car->carCode) {
                    car = var;
                    break;
                }
            }
        }
    };
}
// Класс автомобиля

// Класс владельца


// Класс регистрации


