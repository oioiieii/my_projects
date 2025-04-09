#pragma once

#include "classes.h"
#include "findElementByCode.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <iostream>
#include <mysql_driver.h>

namespace Laba6 {
    using namespace std;

    

    ref class DBWorker
    {
    public:
        static void DropAllTables()
        {
            sql::Connection* conn = ConnectToMySQL();
            if (!conn) return;

            try
            {
                System::Diagnostics::Debug::WriteLine("Dropping all tables...");

                // Запросы для удаления таблиц
                std::vector<std::string> tables = { "registrations", "cars", "owners", "brands", "manufacturers" };
                sql::Statement* stmt = conn->createStatement();

                for (int i = 0; i < tables.size(); i++)
                {
                    std::string dropQuery = "DROP TABLE IF EXISTS " + tables[i] + ";";
                    stmt->execute(dropQuery);
                }

                delete stmt;
                System::Diagnostics::Debug::WriteLine("All tables dropped successfully!");
            }
            catch (sql::SQLException& e)
            {
                System::Diagnostics::Debug::WriteLine("Error dropping tables: " + gcnew String(e.what()));
            }

            CloseConnection(conn);
        }

        static void ExportAll()
        {
            System::Diagnostics::Debug::WriteLine("Starting export...");

            DropAllTables();

            ExportManufacturers();
            ExportBrands();
            ExportOwners();
            ExportCars();
            ExportRegistrations();

            System::Diagnostics::Debug::WriteLine("Export finished!");
        }

    private:
        static sql::Connection* ConnectToMySQL()
        {
            sql::mysql::MySQL_Driver* driver;
            sql::Connection* conn;

            try
            {
                driver = sql::mysql::get_mysql_driver_instance();
                conn = driver->connect("tcp://localhost:3306?characterEncoding=utf8mb4", "root", "root");
                conn->setSchema("laba7");

                sql::Statement* stmt = conn->createStatement();
                stmt->execute("SET NAMES utf8mb4;");
                stmt->execute("SET CHARACTER SET utf8mb4;");

                delete stmt;
                System::Diagnostics::Debug::WriteLine("Connected to MySQL successfully with utf8mb4 encoding!");
            }
            catch (sql::SQLException& e)
            {
                System::Diagnostics::Debug::WriteLine("Failed to connect to MySQL: {0}", gcnew String(e.what()));
                return nullptr;
            }

            return conn;
        }

        static void CloseConnection(sql::Connection* conn)
        {
            if (conn)
            {
                delete conn;
                System::Diagnostics::Debug::WriteLine("Connection closed.");
            }
        }

        static bool DoesTableExist(sql::Connection* conn, const string& tableName)
        {
            try
            {
                sql::Statement* stmt = conn->createStatement();
                sql::ResultSet* res = stmt->executeQuery("SHOW TABLES LIKE '" + tableName + "'");
                bool exists = res->next();
                delete stmt;
                delete res;
                return exists;
            }
            catch (sql::SQLException& e)
            {
                System::Diagnostics::Debug::WriteLine("Error checking table existence: {0}", gcnew String(e.what()));
                return false;
            }
        }

        static void CreateTable(sql::Connection* conn, const string& tableName, const string& createQuery)
        {
            try
            {
                sql::Statement* stmt = conn->createStatement();
                stmt->execute(createQuery);
                delete stmt;
            }
            catch (sql::SQLException& e)
            {
                System::Diagnostics::Debug::WriteLine("Failed to create table {0}: {1}", gcnew String(tableName.c_str()), gcnew String(e.what()));
            }
        }

        static void UpdateTableStructureForDynamicFields(sql::Connection* conn, List<Tuple<int, String^, String^>^>^ DynamicFields, String^ table_name)
        {
            for each (Tuple<int, String^, String^> ^ field in DynamicFields)
            {
                String^ fieldName = field->Item2;
                String^ defaultValue = field->Item3;
                String^ fieldType;

                // Определяем тип столбца
                switch (field->Item1)
                {
                case (int)FieldType::Integer:
                    fieldType = "INT";
                    break;
                case (int)FieldType::String:
                    fieldType = "VARCHAR(255)";
                    break;
                case (int)FieldType::Date:
                    fieldType = "DATE";
                    break;
                case (int)FieldType::Float:
                    fieldType = "FLOAT";
                    break;
                default:
                    continue;
                }

                // Проверяем, существует ли столбец в таблице
                String^ checkColumnQuery = String::Format(
                    "SELECT COUNT(*) FROM information_schema.columns "
                    "WHERE table_name = '{1}' AND column_name = '{0}' AND table_schema = DATABASE();",
                    fieldName, table_name
                );

                sql::Statement* stmt = conn->createStatement();
                sql::ResultSet* res = stmt->executeQuery(convert_to_string(checkColumnQuery));

                res->next();
                bool columnExists = res->getInt(1) > 0;

                delete res;
                delete stmt;

                // Если столбец отсутствует, добавляем его
                if (!columnExists)
                {
                    String^ alterQuery = String::Format(
                        "ALTER TABLE {3} ADD COLUMN `{0}` {1} DEFAULT '{2}';",
                        fieldName,
                        fieldType,
                        defaultValue, table_name
                    );
                    ExecuteQuery(conn, alterQuery);
                }
            }
        }

        static void ExportDynamicFields(sql::Connection* conn, IDynamicFields^ dynamicField, String^ mainColumn, String^ tableName)
        {
            List<String^>^ dynamicValues = dynamicField->getDynamicValues();

            for (int i = 0; i < dynamicField->getDynamicFields()->Count; i++)
            {
                String^ fieldName = dynamicField->getDynamicFields()[i]->Item2;
                String^ value = dynamicValues[i];

                if (dynamicField->getDynamicFields()[i]->Item1 == (int)FieldType::Date) {
                    DateTime dateValue;
                    if (DateTime::TryParseExact(value, "dd.MM.yyyy", nullptr, System::Globalization::DateTimeStyles::None, dateValue))
                    {
                        value = dateValue.ToString("yyyy-MM-dd");
                    }
                    else
                    {
                        // Ошибка преобразования, возможно логировать или обработать иначе
                        System::Diagnostics::Debug::WriteLine("Invalid date format: {0}", value);
                    }
                }

                if (value == nullptr || value->Trim()->Length == 0)
                {
                    value = dynamicField->getDynamicFields()[i]->Item3; // Значение по умолчанию
                }
                else
                {
                    value = String::Format("'{0}'", value->Replace("'", "''"));
                }

                String^ updateQuery = String::Format(
                    "UPDATE {3} SET `{0}` = {1} WHERE {4} = {2};",
                    fieldName,
                    value,
                    dynamicField->getID(), tableName, mainColumn
                );

                ExecuteQuery(conn, updateQuery);
            }
        }

        static void ExportManufacturers()
        {
            sql::Connection* conn = ConnectToMySQL();
            if (!conn) return;

            if (!DoesTableExist(conn, "manufacturers"))
            {
                string createQuery = "CREATE TABLE manufacturers ("
                    "ManufacturerCode INT PRIMARY KEY,"
                    "Name VARCHAR(255),"
                    "Address VARCHAR(255)"
                    ");";
                CreateTable(conn, "manufacturers", createQuery);
            }

            // Добавляем недостающие столбцы для динамических полей
            UpdateTableStructureForDynamicFields(conn, Manufacturer::DynamicFields, "manufacturers");

            // Экспортируем данные
            for each (Manufacturer ^ manufacturer in Manufacturer::manufacturers)
            {
                String^ query = BuildManufacturerQuery(manufacturer);
                ExecuteQuery(conn, query);

                // Экспортируем динамические поля
                ExportDynamicFields(conn, manufacturer, "ManufacturerCode", "manufacturers");
            }

            CloseConnection(conn);
        }

        static void ExportBrands()
        {
            sql::Connection* conn = ConnectToMySQL();
            if (!conn) return;

            if (!DoesTableExist(conn, "Brands"))
            {
                string createQuery = "CREATE TABLE Brands ("
                    "BrandCode INT PRIMARY KEY,"
                    "Name VARCHAR(255),"
                    "ManufacturerCode INT,"
                    "FOREIGN KEY (ManufacturerCode) REFERENCES manufacturers(ManufacturerCode)"
                    ");";
                CreateTable(conn, "Brands", createQuery);
            }

            // Добавляем недостающие столбцы для динамических полей
            UpdateTableStructureForDynamicFields(conn, Brand::DynamicFields, "brands");

            for each (Brand ^ brand in Brand::brands)
            {
                String^ query = BuildBrandQuery(brand);
                ExecuteQuery(conn, query);

                ExportDynamicFields(conn, brand, "BrandCode", "Brands");
            }

            CloseConnection(conn);
        }

        static void ExportOwners()
        {
            sql::Connection* conn = ConnectToMySQL();
            if (!conn) return;

            if (!DoesTableExist(conn, "Owners"))
            {
                string createQuery = "CREATE TABLE Owners ("
                    "OwnerCode INT PRIMARY KEY,"
                    "FullName VARCHAR(255),"
                    "Address VARCHAR(255)"
                    ");";
                CreateTable(conn, "Owners", createQuery);
            }
            // Добавляем недостающие столбцы для динамических полей
            UpdateTableStructureForDynamicFields(conn, Laba6::Owner::DynamicFields, "owners");

            for each (Owner ^ owner in Owner::owners)
            {
                String^ query = BuildOwnerQuery(owner);
                ExecuteQuery(conn, query);

                ExportDynamicFields(conn, owner, "OwnerCode", "Owners");
            }

            CloseConnection(conn);
        }

        static void ExportCars()
        {
            sql::Connection* conn = ConnectToMySQL();
            if (!conn) return;

            if (!DoesTableExist(conn, "Cars"))
            {
                string createQuery = "CREATE TABLE Cars ("
                    "CarCode INT PRIMARY KEY,"
                    "BrandCode INT,"
                    "ChassisNumber VARCHAR(255),"
                    "EngineNumber VARCHAR(255),"
                    "FOREIGN KEY (BrandCode) REFERENCES Brands(BrandCode)"
                    ");";
                CreateTable(conn, "Cars", createQuery);
            }
            // Добавляем недостающие столбцы для динамических полей
            UpdateTableStructureForDynamicFields(conn, Laba6::Car::DynamicFields, "cars");

            for each (Car ^ car in Car::cars)
            {
                String^ query = BuildCarQuery(car);
                ExecuteQuery(conn, query);

                ExportDynamicFields(conn, car, "CarCode", "Cars");
            }

            CloseConnection(conn);
        }

        static void ExportRegistrations()
        {
            sql::Connection* conn = ConnectToMySQL();
            if (!conn) return;

            if (!DoesTableExist(conn, "Registrations"))
            {
                string createQuery = "CREATE TABLE Registrations ("
                    "RegistrationCode INT PRIMARY KEY,"
                    "OwnerCode INT,"
                    "CarCode INT,"
                    "Date DATE,"
                    "FOREIGN KEY (OwnerCode) REFERENCES Owners(OwnerCode),"
                    "FOREIGN KEY (CarCode) REFERENCES Cars(CarCode)"
                    ");";
                CreateTable(conn, "Registrations", createQuery);
            }
            // Добавляем недостающие столбцы для динамических полей
            UpdateTableStructureForDynamicFields(conn, Laba6::Registration::DynamicFields, "Registrations");


            for each (Registration ^ registration in Registration::registrations)
            {
                String^ query = BuildRegistrationQuery(registration);
                ExecuteQuery(conn, query);

                ExportDynamicFields(conn, registration, "RegistrationCode", "Registrations");
            }

            CloseConnection(conn);
        }

        static String^ BuildManufacturerQuery(Manufacturer^ manufacturer)
        {
            String^ query = String::Format(
                "INSERT INTO manufacturers (ManufacturerCode, Name, Address) VALUES ({0}, '{1}', '{2}') ON DUPLICATE KEY UPDATE Name='{1}', Address='{2}';",
                manufacturer->ManufacturerCode ,
                manufacturer->Name->Replace("'", "''"),
                manufacturer->Address->Replace("'", "''")
            );
            return query;
        }

        static String^ BuildBrandQuery(Brand^ brand)
        {
            return String::Format(
                "INSERT INTO Brands (BrandCode, Name, ManufacturerCode) VALUES ({0}, '{1}', {2}) ON DUPLICATE KEY UPDATE Name='{1}', ManufacturerCode={2};",
                brand->brandCode ,
                brand->name->Replace("'", "''"),
                brand->manufacturer->ManufacturerCode
            );
        }

        static String^ BuildOwnerQuery(Owner^ owner)
        {
            return String::Format(
                "INSERT INTO Owners (OwnerCode, FullName, Address) VALUES ({0}, '{1}', '{2}') ON DUPLICATE KEY UPDATE FullName='{1}', Address='{2}';",
                owner->ownerCode ,
                owner->fullName->Replace("'", "''"),
                owner->address->Replace("'", "''")
            );
        }

        static String^ BuildCarQuery(Car^ car)
        {
            return String::Format(
                "INSERT INTO Cars (CarCode, BrandCode, ChassisNumber, EngineNumber) VALUES ({0}, {1}, '{2}', '{3}') ON DUPLICATE KEY UPDATE BrandCode={1}, ChassisNumber='{2}', EngineNumber='{3}';",
                car->carCode ,
                car->brand->brandCode,
                car->chassisNumber->Replace("'", "''"),
                car->engineNumber->Replace("'", "''")
            );
        }

        static String^ BuildRegistrationQuery(Registration^ registration)
        {
            // Преобразование даты из строки dd.MM.YYYY в формат YYYY-MM-DD
            String^ string = registration->date;
            DateTime dateValue;
            if (DateTime::TryParseExact(string, "dd.MM.yyyy", nullptr, System::Globalization::DateTimeStyles::None, dateValue))
            {
                String^ formattedDate = dateValue.ToString("yyyy-MM-dd");

                return String::Format(
                    "INSERT INTO Registrations (RegistrationCode, OwnerCode, CarCode, Date) VALUES ({0}, {1}, {2}, '{3}') ON DUPLICATE KEY UPDATE OwnerCode={1}, CarCode={2}, Date='{3}';",
                    registration->registrationCode,
                    registration->owner->ownerCode,
                    registration->car->carCode,
                    formattedDate->Replace("'", "''") // Замена апострофов в строке
                );
            }
            else
            {
                // Ошибка преобразования, возможно логировать или обработать иначе
                System::Diagnostics::Debug::WriteLine("Invalid date format: {0}", registration->date);
                return nullptr; // Или верните сообщение об ошибке
            }
        }

        static std::string ConvertStringToStdString(System::String^ managedString)
        {
            System::Text::Encoding^ encoding = System::Text::Encoding::UTF8;
            String^ encodedString = encoding->GetString(encoding->GetBytes(managedString));
            const char* nativeString = (const char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(encodedString).ToPointer();
            std::string stdString(nativeString);
            System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)nativeString));
            return stdString;
        }

        static void ExecuteQuery(sql::Connection* conn, System::String^ query)
        {
            try
            {
                string u8_query = convert_to_string(query);
                sql::Statement* stmt = conn->createStatement();
                stmt->execute(u8_query);
                System::Diagnostics::Debug::WriteLine("Query executed successfully!");
                delete stmt;
            }
            catch (sql::SQLException& e)
            {
                System::Diagnostics::Debug::WriteLine("Query failed: {0}", gcnew String(e.what()));
            }
        }

    public:
        static std::string convert_to_string(System::String^ txt_input);
        static String^ FixEncoding(const std::string& str);
        
    
        static void ImportAll()
        {
            System::Diagnostics::Debug::WriteLine("Starting import...");

            Manufacturer::manufacturers = ImportManufacturers();
            Brand::brands = ImportBrands();
            Owner::owners = ImportOwners();
            Car::cars = ImportCars();
            Registration::registrations = ImportRegistrations();

            System::Diagnostics::Debug::WriteLine("Import finished!");
        }

        // Метод для получения значения по умолчанию из базы данных
        static String^ GetDefaultValueForColumn(sql::Connection* conn, String^ tableName, String^ columnName)
        {
            // Создаём запрос для получения значения по умолчанию
            String^ query = String::Format(
                "SELECT COLUMN_DEFAULT FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_SCHEMA = 'laba7' AND TABLE_NAME = '{0}' AND COLUMN_NAME = '{1}';",
                tableName, columnName
            );

            sql::Statement* stmt = conn->createStatement();
            sql::ResultSet* res = stmt->executeQuery(convert_to_string(query));

            String^ defaultValue = nullptr;
            if (res->next()) {
                defaultValue = FixEncoding(res->getString("COLUMN_DEFAULT").c_str());
            }

            delete stmt;
            return defaultValue;
        }

        static void ImportDynamicFields(sql::ResultSet* res, sql::Connection* conn, String^ tableName, int n, List<Tuple<int, String^, String^>^>^ dynamicFields)
        {
            dynamicFields->Clear();
            // Получаем количество столбцов в ResultSet
            int columnCount = res->getMetaData()->getColumnCount();

            for (int i = n; i < columnCount + 1; i++) // Пропускаем первые n колонок
            {
                // Получаем имя текущей колонки
                String^ columnName = FixEncoding(res->getMetaData()->getColumnName(i));

                // Определение типа поля по имени колонки
                int fieldType;
                String^ columnType = FixEncoding(res->getMetaData()->getColumnTypeName(i));

                if (columnType == "INT") {
                    fieldType = (int)FieldType::Integer;
                }
                else if (columnType == "VARCHAR" || columnType == "TEXT") {
                    fieldType = (int)FieldType::String;
                }
                else if (columnType == "DATE") {
                    fieldType = (int)FieldType::Date;
                }
                else if (columnType == "FLOAT") {
                    fieldType = (int)FieldType::Float;
                }
                else {
                    fieldType = -1; // Если тип не известен
                }

                // Попробуем извлечь значение колонки
                String^ fieldValue;
                try {
                    fieldValue = GetDefaultValueForColumn(conn, tableName, columnName);
                }
                catch (...) {
                    // Устанавливаем значение по умолчанию, если возникла ошибка
                    fieldValue = ""; // Здесь можно указать конкретное значение по умолчанию
                }

                // Добавляем информацию о поле в список dynamicFields
                dynamicFields->Add(gcnew Tuple<int, String^, String^>(fieldType, columnName, fieldValue));
            }
        }

        static void TakeDynamicValues(sql::ResultSet* res, List<Tuple<int, String^, String^>^>^ dynamicFields, List<String^>^ dynamicValues) {
            for each (Tuple<int, String^, String^> ^ field in dynamicFields)
            {
                String^ fieldName = field->Item2;
                try
                {
                    String^ fieldValue = FixEncoding(res->getString(convert_to_string(fieldName)).c_str());
                    if (field->Item1 == (int)FieldType::Date) {
                        DateTime parsedDate;
                        if (DateTime::TryParseExact(fieldValue, "yyyy-MM-dd", nullptr, System::Globalization::DateTimeStyles::None, parsedDate)) {
                            // Переобразуем дату в нужный формат
                            String^ formattedDate = parsedDate.ToString("dd.MM.yyyy");
                            fieldValue = formattedDate;
                        }
                    }
                    
                    dynamicValues->Add(fieldValue);
                }
                catch (...)
                {
                    dynamicValues->Add(field->Item3); // DefaultValue
                }
            }
        }

        // Импорт производителей
        static ArrayList^ ImportManufacturers()
        {
            sql::Connection* conn = ConnectToMySQL();
            if (!conn) return gcnew ArrayList();

            ArrayList^ manufacturers = gcnew ArrayList();

            try
            {
                string query = "SELECT * FROM manufacturers;";
                sql::Statement* stmt = conn->createStatement();
                sql::ResultSet* res = stmt->executeQuery(query);

                //Смотрим наличие динамических полей
                ImportDynamicFields(res, conn, "manufacturers", 4, Manufacturer::DynamicFields);

                while (res->next())
                {
                    int code = res->getInt("ManufacturerCode");
                    String^ name = FixEncoding(res->getString("Name"));
                    String^ address = FixEncoding(res->getString("Address").c_str());

                    List<String^>^ dynamicValues = gcnew List<String^>();
                    TakeDynamicValues(res, Manufacturer::DynamicFields, dynamicValues);

                    Manufacturer^ manufacturer = gcnew Manufacturer(code, name, address, dynamicValues);

                    manufacturers->Add(manufacturer);
                }

                delete res;
                delete stmt;
            }
            catch (sql::SQLException& e)
            {
                System::Diagnostics::Debug::WriteLine(gcnew String(e.what()));
            }

            CloseConnection(conn);
            return manufacturers;
        }

        // Импорт брендов
        static ArrayList^ ImportBrands()
        {
            sql::Connection* conn = ConnectToMySQL();
            if (!conn) return gcnew ArrayList();

            ArrayList^ brands = gcnew ArrayList();

            try
            {
                string query = "SELECT * FROM brands;";
                sql::Statement* stmt = conn->createStatement();
                sql::ResultSet* res = stmt->executeQuery(query);

                // Проверяем наличие динамических полей
                ImportDynamicFields(res, conn, "brands", 4, Brand::DynamicFields);

                while (res->next())
                {
                    int code = res->getInt("BrandCode");
                    String^ name = FixEncoding(res->getString("Name").c_str());
                    int manufacturerCode = res->getInt("ManufacturerCode");

                    Manufacturer^ manufacturer = static_cast<Manufacturer^>(findElementByCodeClass::findElementByCode(manufacturerCode, TableType::Manufacturers));

                    List<String^>^ dynamicValues = gcnew List<String^>();
                    TakeDynamicValues(res, Brand::DynamicFields, dynamicValues);

                    Brand^ brand = gcnew Brand(code, name, manufacturer, dynamicValues);
                    brand->CheckDynamicValues(dynamicValues);

                    brands->Add(brand);
                }

                delete res;
                delete stmt;
            }
            catch (sql::SQLException& e)
            {
                System::Diagnostics::Debug::WriteLine(gcnew String(e.what()));
            }

            CloseConnection(conn);
            return brands;
        }


        // Импорт владельцев
        static ArrayList^ ImportOwners()
        {
            sql::Connection* conn = ConnectToMySQL();
            if (!conn) return gcnew ArrayList();

            ArrayList^ owners = gcnew ArrayList();

            try
            {
                string query = "SELECT * FROM owners;";
                sql::Statement* stmt = conn->createStatement();
                sql::ResultSet* res = stmt->executeQuery(query);

                // Проверяем наличие динамических полей
                ImportDynamicFields(res, conn, "owners", 4, Owner::DynamicFields);

                while (res->next())
                {
                    int id = res->getInt("OwnerCode");
                    String^ name = FixEncoding(res->getString("FullName").c_str());
                    String^ address = FixEncoding(res->getString("Address").c_str());

                    List<String^>^ dynamicValues = gcnew List<String^>();
                    TakeDynamicValues(res, Owner::DynamicFields, dynamicValues);

                    Owner^ owner = gcnew Owner(id, name, address, dynamicValues);
                    owner->CheckDynamicValues(dynamicValues);

                    owners->Add(owner);
                }

                delete res;
                delete stmt;
            }
            catch (sql::SQLException& e)
            {
                System::Diagnostics::Debug::WriteLine(gcnew String(e.what()));
            }

            CloseConnection(conn);
            return owners;
        }

        // Импорт автомобилей
        static ArrayList^ ImportCars()
        {
            sql::Connection* conn = ConnectToMySQL();
            if (!conn) return gcnew ArrayList();

            ArrayList^ cars = gcnew ArrayList();

            try
            {
                string query = "SELECT * FROM cars;";
                sql::Statement* stmt = conn->createStatement();
                sql::ResultSet* res = stmt->executeQuery(query);

                // Проверяем наличие динамических полей
                ImportDynamicFields(res, conn, "cars", 5, Car::DynamicFields);

                while (res->next())
                {
                    int code = res->getInt("CarCode");
                    int brandCode = res->getInt("BrandCode");
                    String^ chassisNumber = FixEncoding(res->getString("ChassisNumber").c_str());
                    String^ engineNumber = FixEncoding(res->getString("EngineNumber").c_str());

                    Brand^ brand = static_cast<Brand^>(findElementByCodeClass::findElementByCode(brandCode, TableType::Brands));

                    List<String^>^ dynamicValues = gcnew List<String^>();
                    TakeDynamicValues(res, Car::DynamicFields, dynamicValues);

                    Car^ car = gcnew Car(code, brand, chassisNumber, engineNumber, dynamicValues);
                    car->CheckDynamicValues(dynamicValues);

                    cars->Add(car);
                }

                delete res;
                delete stmt;
            }
            catch (sql::SQLException& e)
            {
                System::Diagnostics::Debug::WriteLine(gcnew String(e.what()));
            }

            CloseConnection(conn);
            return cars;
        }

        // Импорт регистраций
        static ArrayList^ ImportRegistrations()
        {
            sql::Connection* conn = ConnectToMySQL();
            if (!conn) return gcnew ArrayList();

            ArrayList^ registrations = gcnew ArrayList();

            try
            {
                string query = "SELECT * FROM registrations;";
                sql::Statement* stmt = conn->createStatement();
                sql::ResultSet* res = stmt->executeQuery(query);

                // Проверяем наличие динамических полей
                ImportDynamicFields(res, conn, "registrations", 5, Registration::DynamicFields);

                while (res->next())
                {
                    int code = res->getInt("RegistrationCode");
                    int ownerCode = res->getInt("OwnerCode");
                    int carCode = res->getInt("CarCode");

                    String^ date = FixEncoding(res->getString("Date").c_str());
                    if (date != nullptr) {
                        DateTime parsedDate;
                        if (DateTime::TryParseExact(date, "yyyy-MM-dd", nullptr, System::Globalization::DateTimeStyles::None, parsedDate)) {
                            // Переобразуем дату в нужный формат
                            String^ formattedDate = parsedDate.ToString("dd.MM.yyyy");
                            date = formattedDate;
                        }
                    }

                    Owner^ owner = static_cast<Owner^>(findElementByCodeClass::findElementByCode(ownerCode, TableType::Owners));
                    Car^ car = static_cast<Car^>(findElementByCodeClass::findElementByCode(carCode, TableType::Cars));

                    List<String^>^ dynamicValues = gcnew List<String^>();
                    TakeDynamicValues(res, Registration::DynamicFields, dynamicValues);

                    Registration^ registration = gcnew Registration(code, owner, car, date, dynamicValues);
                    registration->CheckDynamicValues(dynamicValues);

                    registrations->Add(registration);
                }

                delete res;
                delete stmt;
            }
            catch (sql::SQLException& e)
            {
                System::Diagnostics::Debug::WriteLine(gcnew String(e.what()));
            }

            CloseConnection(conn);
            return registrations;
        }

};

}

