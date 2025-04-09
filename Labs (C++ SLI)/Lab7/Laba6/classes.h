#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

    enum class TableType
    {
        Brands,
        Manufacturers,
        Owners,
        Cars,
        Registrations
    };

    enum class FieldType
    {
        Integer,
        Float,
        String,
        Date
    };

    namespace Laba6 {
        using namespace System::Collections;
        using namespace System;
        using namespace System::ComponentModel;
        using namespace System::Collections::Generic;

        interface class IDynamicFields {
            virtual List<Tuple<int, String^, String^>^>^ getDynamicFields();
            virtual List<String^>^ getDynamicValues();
            virtual int getID();
            virtual ArrayList^ getArrayList();
        };

    // Класс производителя
    ref class Manufacturer: IDynamicFields {
    public:
        static int counter = 0;
        static ArrayList^ manufacturers = gcnew ArrayList();

        property Manufacturer^ This;
        property int ManufacturerCode;
        property System::String^ Name;
        property System::String^ Address;

        

        //Динмаические поля
        virtual List<Tuple<int, String^, String^>^>^ getDynamicFields() override {
            return DynamicFields;
        }
        virtual List<String^>^ getDynamicValues() override {
            return DynamicValues;
        }
        virtual int getID() {
            return ManufacturerCode;
        }
        virtual ArrayList^ getArrayList() {
            return manufacturers;
        }

        static void AddNewField(int typeField, String^ nameField, String^ defaultValue) {
            DynamicFields->Add(gcnew Tuple<int, String^, String^>(typeField, nameField, defaultValue));
            if (manufacturers->Count != 0) {
                for each (Manufacturer ^ manufacturer in manufacturers) {
                    manufacturer->DynamicValues->Add(defaultValue);
                }
            }
        }
        static List<Tuple<int, String^, String^>^>^ DynamicFields = gcnew List<Tuple<int, String^, String^>^>();
        List<String^>^ DynamicValues = gcnew List<String^>();

        void CheckDynamicValues(List<String^>^ dynamicValues) {
            for (int i = 0; i < DynamicFields->Count; i++) {
                if (i >= dynamicValues->Count) {
                    DynamicValues->Add(DynamicFields[i]->Item3);
                }
                else {
                    DynamicValues->Add(dynamicValues[i]);
                }
            }
        }

        Manufacturer() {
            This = this;
            ManufacturerCode = -1;
            Name = nullptr;
            Address = nullptr;
        }

        Manufacturer(System::String^ name, System::String^ address, List<String^>^ _dynamicValues) {
            This = this;
            ManufacturerCode = counter++;
            Name = name;
            Address = address;

            //Проверка динамических полей
            CheckDynamicValues(_dynamicValues);
        }

        Manufacturer(int code, System::String^ name, System::String^ address, List<String^>^ _dynamicValues) {
            This = this;
            ManufacturerCode = code;
            if (counter <= code) counter = code + 1;
            Name = name;
            Address = address;

            CheckDynamicValues(_dynamicValues);
        }
        Manufacturer(Manufacturer^ manufacturer) {
            This = this;
            ManufacturerCode = manufacturer->ManufacturerCode;
            if (counter <= manufacturer->ManufacturerCode) counter = manufacturer->ManufacturerCode + 1;
            Name = manufacturer->Name;
            Address = manufacturer->Address;
            DynamicValues = manufacturer->DynamicValues;
        }
    };
    

    // Класс марки
    ref class Brand : IDynamicFields {
    public:
        static int counter = 0;
        static ArrayList^ brands = gcnew ArrayList();

        property Brand^ This;
        property int brandCode;
        property System::String^ name;
        property Manufacturer^ manufacturer;

        virtual List<Tuple<int, String^, String^>^>^ getDynamicFields() override {
            return DynamicFields;
        }
        virtual List<String^>^ getDynamicValues() override {
            return DynamicValues;
        }
        virtual int getID() {
            return brandCode;
        }
        virtual ArrayList^ getArrayList() {
            return brands;
        }


        static void AddNewField(int typeField, String^ nameField, String^ defaultValue) {
            DynamicFields->Add(gcnew Tuple<int, String^, String^>(typeField, nameField, defaultValue));
            if (brands->Count != 0) {
                for each (Brand ^ brand in brands) {
                    brand->DynamicValues->Add(defaultValue);
                }
            }
        }

        static List<Tuple<int, String^, String^>^>^ DynamicFields = gcnew List<Tuple<int, String^, String^>^>();
        List<String^>^ DynamicValues = gcnew List<String^>();

        void CheckDynamicValues(List<String^>^ dynamicValues) {
            for (int i = 0; i < DynamicFields->Count; i++) {
                if (i >= dynamicValues->Count) {
                    DynamicValues->Add(DynamicFields[i]->Item3);
                }
                else {
                    DynamicValues->Add(dynamicValues[i]);
                }
            }
        }

        Brand() {
            This = this;
            brandCode = -1;
            name = nullptr;
            manufacturer = nullptr;
        }

        Brand(System::String^ name_, Manufacturer^ manufacturer_, List<String^>^ _dynamicValues) {
            This = this;
            brandCode = counter++;
            name = name_;
            manufacturer = manufacturer_;
            CheckDynamicValues(_dynamicValues);
        }

        Brand(int code_, System::String^ name_, Manufacturer^ manufacturer_, List<String^>^ _dynamicValues) {
            This = this;
            brandCode = code_;
            if (counter <= code_) counter = code_ + 1;
            name = name_;
            manufacturer = manufacturer_;
            CheckDynamicValues(_dynamicValues);
        }

        Brand(Brand^ brand, List<Manufacturer^>^ array) {
            This = this;
            brandCode = brand->brandCode;
            name = brand->name;
            DynamicValues = brand->DynamicValues;

            for each (Manufacturer ^ var in array) {
                if (var->ManufacturerCode == brand->manufacturer->ManufacturerCode) {
                    manufacturer = var;
                    break;
                }
            }
        }
    };

    
    // Класс владельца
    ref class Owner : IDynamicFields {
    public:
        static int counter = 0;
        static ArrayList^ owners = gcnew ArrayList();

        property Owner^ This;
        property int ownerCode;
        property System::String^ fullName;
        property System::String^ address;

        virtual List<Tuple<int, String^, String^>^>^ getDynamicFields() override {
            return DynamicFields;
        }
        virtual List<String^>^ getDynamicValues() override {
            return DynamicValues;
        }
        virtual int getID() {
            return ownerCode;
        }
        virtual ArrayList^ getArrayList() {
            return owners;
        }

        static void AddNewField(int typeField, String^ nameField, String^ defaultValue) {
            DynamicFields->Add(gcnew Tuple<int, String^, String^>(typeField, nameField, defaultValue));
            if (owners->Count != 0) {
                for each (Owner ^ owner in owners) {
                    owner->DynamicValues->Add(defaultValue);
                }
            }
        }

        static List<Tuple<int, String^, String^>^>^ DynamicFields = gcnew List<Tuple<int, String^, String^>^>();
        List<String^>^ DynamicValues = gcnew List<String^>();

        void CheckDynamicValues(List<String^>^ dynamicValues) {
            for (int i = 0; i < DynamicFields->Count; i++) {
                if (i >= dynamicValues->Count) {
                    DynamicValues->Add(DynamicFields[i]->Item3);
                }
                else {
                    DynamicValues->Add(dynamicValues[i]);
                }
            }
        }

        Owner() {
            This = this;
            ownerCode = -1;
            fullName = nullptr;
            address = nullptr;
        }

        Owner(System::String^ fullName_, System::String^ address_, List<String^>^ _dynamicValues) {
            This = this;
            ownerCode = counter++;
            fullName = fullName_;
            address = address_;
            CheckDynamicValues(_dynamicValues);
        }

        Owner(int code, System::String^ fullName_, System::String^ address_, List<String^>^ _dynamicValues) {
            This = this;
            ownerCode = code;
            if (counter <= code) counter = code + 1;
            fullName = fullName_;
            address = address_;
            CheckDynamicValues(_dynamicValues);
        }

        Owner(Owner^ owner) {
            This = this;
            ownerCode = owner->ownerCode;
            fullName = owner->fullName;
            address = owner->address;
            DynamicValues = owner->DynamicValues;
        }
    };

    // Класс автомобиля
    ref class Car : IDynamicFields {
    public:
        static int counter = 0;
        static ArrayList^ cars = gcnew ArrayList();

        property Car^ This;
        property int carCode;
        property Brand^ brand;
        property System::String^ chassisNumber;
        property System::String^ engineNumber;

        virtual List<Tuple<int, String^, String^>^>^ getDynamicFields() override {
            return DynamicFields;
        }
        virtual List<String^>^ getDynamicValues() override {
            return DynamicValues;
        }
        virtual int getID() {
            return carCode;
        }
        virtual ArrayList^ getArrayList() {
            return cars;
        }

        static void AddNewField(int typeField, String^ nameField, String^ defaultValue) {
            DynamicFields->Add(gcnew Tuple<int, String^, String^>(typeField, nameField, defaultValue));
            if (cars->Count != 0) {
                for each (Car ^ car in cars) {
                    car->DynamicValues->Add(defaultValue);
                }
            }
        }

        static List<Tuple<int, String^, String^>^>^ DynamicFields = gcnew List<Tuple<int, String^, String^>^>();
        List<String^>^ DynamicValues = gcnew List<String^>();

        void CheckDynamicValues(List<String^>^ dynamicValues) {
            for (int i = 0; i < DynamicFields->Count; i++) {
                if (i >= dynamicValues->Count) {
                    DynamicValues->Add(DynamicFields[i]->Item3);
                }
                else {
                    DynamicValues->Add(dynamicValues[i]);
                }
            }
        }

        Car() {
            This = this;
            carCode = -1;
            brand = nullptr;
            chassisNumber = nullptr;
            engineNumber = nullptr;
        }

        Car(Brand^ brand_, System::String^ chassisNumber_, System::String^ engineNumber_, List<String^>^ _dynamicValues) {
            This = this;
            carCode = counter++;
            brand = brand_;
            chassisNumber = chassisNumber_;
            engineNumber = engineNumber_;
            CheckDynamicValues(_dynamicValues);
        }

        Car(int code, Brand^ brand_, System::String^ chassisNumber_, System::String^ engineNumber_, List<String^>^ _dynamicValues) {
            This = this;
            carCode = code;
            if (counter <= code) counter = code + 1;
            brand = brand_;
            chassisNumber = chassisNumber_;
            engineNumber = engineNumber_;
            CheckDynamicValues(_dynamicValues);
        }

        Car(Car^ car, List<Brand^>^ array) {
            This = this;
            carCode = car->carCode;
            chassisNumber = car->chassisNumber;
            engineNumber = car->engineNumber;
            DynamicValues = car->DynamicValues;

            for each (Brand ^ var in array) {
                if (var->brandCode == car->brand->brandCode) {
                    brand = var;
                    break;
                }
            }
        }
    };


    // Класс регистрации
    ref class Registration : IDynamicFields {
    public:
        static int counter = 0;
        static ArrayList^ registrations = gcnew ArrayList();

        property Registration^ This;
        property int registrationCode;
        property Owner^ owner;
        property Car^ car;
        property System::String^ date;

        virtual List<Tuple<int, String^, String^>^>^ getDynamicFields() override {
            return DynamicFields;
        }
        virtual List<String^>^ getDynamicValues() override {
            return DynamicValues;
        }
        virtual int getID() {
            return registrationCode;
        }
        virtual ArrayList^ getArrayList() {
            return registrations;
        }

        static void AddNewField(int typeField, String^ nameField, String^ defaultValue) {
            DynamicFields->Add(gcnew Tuple<int, String^, String^>(typeField, nameField, defaultValue));
            if (registrations->Count != 0) {
                for each (Registration ^ registration in registrations) {
                    registration->DynamicValues->Add(defaultValue);
                }
            }
        }

        static List<Tuple<int, String^, String^>^>^ DynamicFields = gcnew List<Tuple<int, String^, String^>^>();
        List<String^>^ DynamicValues = gcnew List<String^>();

        void CheckDynamicValues(List<String^>^ dynamicValues) {
            for (int i = 0; i < DynamicFields->Count; i++) {
                if (i >= dynamicValues->Count) {
                    DynamicValues->Add(DynamicFields[i]->Item3);
                }
                else {
                    DynamicValues->Add(dynamicValues[i]);
                }
            }
        }

        Registration() {
            This = this;
            registrationCode = -1;
            owner = nullptr;
            car = nullptr;
            date = nullptr;
        }

        Registration(Owner^ owner_, Car^ car_, System::String^ date_, List<String^>^ _dynamicValues) {
            This = this;
            registrationCode = counter++;
            owner = owner_;
            car = car_;
            date = date_;
            CheckDynamicValues(_dynamicValues);
        }

        Registration(int code, Owner^ owner_, Car^ car_, System::String^ date_, List<String^>^ _dynamicValues) {
            This = this;
            registrationCode = code;
            if (counter <= code) counter = code + 1;
            owner = owner_;
            car = car_;
            date = date_;
            CheckDynamicValues(_dynamicValues);
        }

        Registration(Registration^ registration, List<Owner^>^ ownerArray, List<Car^>^ carArray) {
            This = this;
            registrationCode = registration->registrationCode;
            date = registration->date;
            DynamicValues = registration->DynamicValues;

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


