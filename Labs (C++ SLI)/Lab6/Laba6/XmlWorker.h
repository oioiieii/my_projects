#pragma once
#include "classes.h"
#include <cliext/list>
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Xml;
using namespace System::IO;
using namespace Laba6;

static ref class XmlWorker
{
public:

    //ЧТЕИНЕ ИЗ ФАЙЛА
    static Manufacturer^ ReadManufacturer(XmlReader^ reader) {
        
        // Читаем данные производителя
        int code = -1;
        String^ name = nullptr;
        String^ address = nullptr;

        while (reader->Read())
        {
            if (reader->IsStartElement("ManufacturerCode"))
            {
                code = Convert::ToInt64(reader->ReadElementContentAsString());
            }
            else if (reader->IsStartElement("Name"))
            {
                name = reader->ReadElementContentAsString();
            }
            else if (reader->IsStartElement("Address"))
            {
                address = reader->ReadElementContentAsString();
            }
            else if (reader->NodeType == XmlNodeType::EndElement && reader->Name == "Manufacturer")
            {
                break; // Завершаем чтение текущего элемента Manufacturer
            }
        }

        if (code != -1 && name != nullptr && address != nullptr)
        {
            return(gcnew Manufacturer(code, name, address));
        }
        else return nullptr;
    }

    static Brand^ ReadBrand(XmlReader^ reader) {

        // Читаем данные производителя
        int code = -1;
        String^ name = nullptr;
        int manufacturerCode = -1;

        while (reader->Read())
        {
            if (reader->IsStartElement("BrandCode"))
            {
                code = Convert::ToInt64(reader->ReadElementContentAsString());
            }
            else if (reader->IsStartElement("Name"))
            {
                name = reader->ReadElementContentAsString();
            }
            else if (reader->IsStartElement("ManufacturerCode"))
            {
                manufacturerCode = Convert::ToInt64(reader->ReadElementContentAsString());
            }
            else if (reader->NodeType == XmlNodeType::EndElement && reader->Name == "Brand")
            {
                break; // Завершаем чтение текущего элемента Manufacturer
            }
        }

        if (code != -1 && name != nullptr && manufacturerCode != -1)
        {
            Manufacturer^ manufacturer = (Manufacturer^)findElementByCode(manufacturerCode, TableType::Manufacturers);
            
            return(gcnew Brand(code, name, manufacturer));
        }
        else return nullptr;
    }

    static Owner^ ReadOwner(XmlReader^ reader) {
        // Читаем данные владельца
        int code = -1;
        String^ fullName = nullptr;
        String^ address = nullptr;

        while (reader->Read()) {
            if (reader->IsStartElement("OwnerCode")) {
                code = Convert::ToInt64(reader->ReadElementContentAsString());
            }
            else if (reader->IsStartElement("FullName")) {
                fullName = reader->ReadElementContentAsString();
            }
            else if (reader->IsStartElement("Address")) {
                address = reader->ReadElementContentAsString();
            }
            else if (reader->NodeType == XmlNodeType::EndElement && reader->Name == "Owner") {
                break; // Завершаем чтение текущего элемента Owner
            }
        }

        if (code != -1 && fullName != nullptr && address != nullptr) {
            return gcnew Owner(code, fullName, address);
        }
        else return nullptr;
    }

    static Car^ ReadCar(XmlReader^ reader) {
        // Читаем данные автомобиля
        int code = -1;
        String^ chassisNumber = nullptr;
        String^ engineNumber = nullptr;
        int brandCode = -1;

        while (reader->Read()) {
            if (reader->IsStartElement("CarCode")) {
                code = Convert::ToInt64(reader->ReadElementContentAsString());
            }
            else if (reader->IsStartElement("ChassisNumber")) {
                chassisNumber = reader->ReadElementContentAsString();
            }
            else if (reader->IsStartElement("EngineNumber")) {
                engineNumber = reader->ReadElementContentAsString();
            }
            else if (reader->IsStartElement("BrandCode")) {
                brandCode = Convert::ToInt64(reader->ReadElementContentAsString());
            }
            else if (reader->NodeType == XmlNodeType::EndElement && reader->Name == "Car") {
                break; // Завершаем чтение текущего элемента Car
            }
        }

        if (code != -1 && chassisNumber != nullptr && engineNumber != nullptr && brandCode != -1) {
            Brand^ brand = (Brand^)findElementByCode(brandCode, TableType::Brands);
            return gcnew Car(code, brand, chassisNumber, engineNumber);
        }
        else return nullptr;
    }

    static Registration^ ReadRegistration(XmlReader^ reader) {
        // Читаем данные регистрации
        int code = -1;
        int ownerCode = -1;
        int carCode = -1;
        String^ date = nullptr;

        while (reader->Read()) {
            if (reader->IsStartElement("RegistrationCode")) {
                code = Convert::ToInt64(reader->ReadElementContentAsString());
            }
            else if (reader->IsStartElement("OwnerCode")) {
                ownerCode = Convert::ToInt64(reader->ReadElementContentAsString());
            }
            else if (reader->IsStartElement("CarCode")) {
                carCode = Convert::ToInt64(reader->ReadElementContentAsString());
            }
            else if (reader->IsStartElement("Date")) {
                date = Convert::ToString(reader->ReadElementContentAsString());
            }
            else if (reader->NodeType == XmlNodeType::EndElement && reader->Name == "Registration") {
                break; // Завершаем чтение текущего элемента Registration
            }
        }

        if (code != -1 && ownerCode != -1 && carCode != -1) {
            Owner^ owner = (Owner^)findElementByCode(ownerCode, TableType::Owners);
            Car^ car = (Car^)findElementByCode(carCode, TableType::Cars);
           
            return gcnew Registration(code, owner, car, date);
        }
        else return nullptr;
    }

    static Tuple<List<Manufacturer^>^, List<Brand^>^, List<Owner^>^, List<Car^>^, List<Registration^>^>^ ReadFromXml(String^ filePath) {
        fileExists(filePath);

        // Проверяем существование файла
        if (!File::Exists(filePath)) {
            return gcnew Tuple<List<Manufacturer^>^, List<Brand^>^, List<Owner^>^, List<Car^>^, List<Registration^>^>(nullptr, nullptr, nullptr, nullptr, nullptr);
        }

        // Создаем списки для хранения данных
        List<Manufacturer^>^ manufacturers = gcnew List<Manufacturer^>();
        List<Brand^>^ brands = gcnew List<Brand^>();
        List<Owner^>^ owners = gcnew List<Owner^>();
        List<Car^>^ cars = gcnew List<Car^>();
        List<Registration^>^ registrations = gcnew List<Registration^>();

        try {
            // Открываем XML-документ для чтения
            XmlReader^ reader = XmlReader::Create(filePath);
            Manufacturer::counter = 0;

            // Читаем данные из XML
            while (reader->Read()) {
                if (reader->IsStartElement("Manufacturer")) {
                    Manufacturer^ manufacturer = ReadManufacturer(reader);
                    if (manufacturer != nullptr) manufacturers->Add(manufacturer);
                }
                else if (reader->IsStartElement("Brand")) {
                    Brand^ brand = ReadBrand(reader);
                    if (brand != nullptr) brands->Add(brand);
                }
                else if (reader->IsStartElement("Owner")) {
                    Owner^ owner = ReadOwner(reader);
                    if (owner != nullptr) owners->Add(owner);
                }
                else if (reader->IsStartElement("Car")) {
                    Car^ car = ReadCar(reader);
                    if (car != nullptr) cars->Add(car);
                }
                else if (reader->IsStartElement("Registration")) {
                    Registration^ registration = ReadRegistration(reader);
                    if (registration != nullptr) registrations->Add(registration);
                }
            }

            reader->Close();
        }
        catch (Exception^) {
            // Если произошла ошибка чтения, возвращаем пустой список и null
            return gcnew Tuple<List<Manufacturer^>^, List<Brand^>^, List<Owner^>^, List<Car^>^, List<Registration^>^>(nullptr, nullptr, nullptr, nullptr, nullptr);
        }

        // Возвращаем заполненные списки
        return gcnew Tuple<List<Manufacturer^>^, List<Brand^>^, List<Owner^>^, List<Car^>^, List<Registration^>^>(manufacturers, brands, owners, cars, registrations);
    }

    //УДАЛЕНИЕ ЗАПИСИ
    static void DeleteManufacturer(Manufacturer^ manufacturer, XmlDocument^ xmlDoc) {
        // Ищем элементы Manufacturer, соответствующие переданному объекту
        XmlNodeList^ manufacturerNodes = xmlDoc->GetElementsByTagName("Manufacturer");

        int i = 0;
        while (i < manufacturerNodes->Count) {
            XmlNode^ node = manufacturerNodes[i];

            // Проверяем совпадение полей ManufacturerCode, Name и Address
            int code = node["ManufacturerCode"] != nullptr ? Convert::ToInt64(node["ManufacturerCode"]->InnerText) : -1;
            

            if (code == manufacturer->ManufacturerCode)
            {
                // Удаляем найденный элемент
                node->ParentNode->RemoveChild(node);
            }
            else {
                i++;
            }
        }
    }

    static void DeleteBrand(Brand^ brand, XmlDocument^ xmlDoc) {
        // Ищем элементы Brand, соответствующие переданному объекту
        XmlNodeList^ brandNodes = xmlDoc->GetElementsByTagName("Brand");

        int i = 0;
        while (i < brandNodes->Count) {
            XmlNode^ node = brandNodes[i];

            // Проверяем совпадение полей BrandCode, Name и ManufacturerCode
            int code = node["BrandCode"] != nullptr ? Convert::ToInt64(node["BrandCode"]->InnerText) : -1;
            
            if (code == brand->brandCode) {
                // Удаляем найденный элемент
                node->ParentNode->RemoveChild(node);
            }
            else {
                i++;
            }
        }
    }

    static void DeleteOwner(Owner^ owner, XmlDocument^ xmlDoc) {
        // Ищем элементы Owner, соответствующие переданному объекту
        XmlNodeList^ ownerNodes = xmlDoc->GetElementsByTagName("Owner");

        int i = 0;
        while (i < ownerNodes->Count) {
            XmlNode^ node = ownerNodes[i];

            // Проверяем совпадение полей OwnerCode, FullName и Address
            int code = node["OwnerCode"] != nullptr ? Convert::ToInt64(node["OwnerCode"]->InnerText) : -1;
            
            if (code == owner->ownerCode) {
                // Удаляем найденный элемент
                node->ParentNode->RemoveChild(node);
            }
            else {
                i++;
            }
        }
    }

    static void DeleteCar(Car^ car, XmlDocument^ xmlDoc) {
        // Ищем элементы Car, соответствующие переданному объекту
        XmlNodeList^ carNodes = xmlDoc->GetElementsByTagName("Car");

        int i = 0;
        while (i < carNodes->Count) {
            XmlNode^ node = carNodes[i];

            // Проверяем совпадение полей ManufacturerCode, Name и Address
            int code = node["CarCode"] != nullptr ? Convert::ToInt64(node["CarCode"]->InnerText) : -1;

            if (code == car->carCode) {
                // Удаляем найденный элемент
                node->ParentNode->RemoveChild(node);
            }
            else {
                i++;
            }
        }
    }

    static void DeleteRegistration(Registration^ registration, XmlDocument^ xmlDoc) {
        // Ищем элементы Registration, соответствующие переданному объекту
        XmlNodeList^ registrationNodes = xmlDoc->GetElementsByTagName("Registration");

        int i = 0;
        while (i < registrationNodes->Count) {
            XmlNode^ node = registrationNodes[i];

            // Проверяем совпадение полей RegistrationCode, OwnerCode, CarCode, Date и CarNumber
            int code = node["RegistrationCode"] != nullptr ? Convert::ToInt64(node["RegistrationCode"]->InnerText) : -1;

            if (code == registration->registrationCode) {
                // Удаляем найденный элемент
                node->ParentNode->RemoveChild(node);
            }
            else {
                i++;
            }
        }
    }

    static bool DeleteFromXml(String^ filePath, Object^ object) {
        // Проверяем, существует ли файл
        if (!System::IO::File::Exists(filePath)) {
            return false;
        }

        try {
            // Загружаем XML-документ
            XmlDocument^ xmlDoc = gcnew XmlDocument();
            xmlDoc->Load(filePath);

            // Удаляем производителя, марку, владельца, автомобиль или регистрацию
            if (dynamic_cast<Manufacturer^>(object) != nullptr) {
                DeleteManufacturer((Manufacturer^)object, xmlDoc);
            }
            else if (dynamic_cast<Brand^>(object) != nullptr) {
                DeleteBrand((Brand^)object, xmlDoc);
            }
            else if (dynamic_cast<Owner^>(object) != nullptr) {
                DeleteOwner((Owner^)object, xmlDoc);
            }
            else if (dynamic_cast<Car^>(object) != nullptr) {
                DeleteCar((Car^)object, xmlDoc);
            }
            else if (dynamic_cast<Registration^>(object) != nullptr) {
                DeleteRegistration((Registration^)object, xmlDoc);
            }

            // Сохраняем изменения в файл
            xmlDoc->Save(filePath);

            return true;
        }
        catch (Exception^ ex) {
            System::Windows::Forms::MessageBox::Show(("Ошибка удаления элемента из XML: {0}", ex->Message));
            return false;
        }
    }

    private:
        static void fileExists(String^ filePath) {
            // Если файл отсутствует, создаем новый XML-документ с корневым элементом
            if (!System::IO::File::Exists(filePath))
            {
                XmlDocument^ newXmlDoc = gcnew XmlDocument();

                // Создаем декларацию XML
                XmlDeclaration^ declaration = newXmlDoc->CreateXmlDeclaration("1.0", "UTF-8", "yes");
                newXmlDoc->AppendChild(declaration);

                // Добавляем корневой элемент (например, <Manufacturers>)
                XmlElement^ root = newXmlDoc->CreateElement("Tables");
                newXmlDoc->AppendChild(root);

                root->AppendChild(newXmlDoc->CreateElement("Manufactures"));
                root->AppendChild(newXmlDoc->CreateElement("Brands"));
                root->AppendChild(newXmlDoc->CreateElement("Owners"));
                root->AppendChild(newXmlDoc->CreateElement("Cars"));
                root->AppendChild(newXmlDoc->CreateElement("Registrations"));

                // Сохраняем новый документ
                newXmlDoc->Save(filePath);
            }

        }
    
    public:


    //ДОБВЛЕНИЕ ЗАПИСИ
    
        static bool AddToXml(String^ filePath, Object^ object)
        {
            try
            {
                fileExists(filePath);

                // Загружаем XML-документ
                XmlDocument^ xmlDoc = gcnew XmlDocument();
                xmlDoc->Load(filePath);

                // Добавляем производителя
                if (dynamic_cast<Manufacturer^>(object) != nullptr)
                {
                    AddManufacturer((Manufacturer^)object, xmlDoc);
                }
                // Добавляем марку
                else if (dynamic_cast<Brand^>(object) != nullptr)
                {
                    AddBrand((Brand^)object, xmlDoc);
                }
                // Добавляем владельца
                else if (dynamic_cast<Owner^>(object) != nullptr)
                {
                    AddOwner((Owner^)object, xmlDoc);
                }
                // Добавляем автомобиль
                else if (dynamic_cast<Car^>(object) != nullptr)
                {
                    AddCar((Car^)object, xmlDoc);
                }
                // Добавляем регистрацию
                else if (dynamic_cast<Registration^>(object) != nullptr)
                {
                    AddRegistration((Registration^)object, xmlDoc);
                }

                // Сохраняем изменения в файл
                xmlDoc->Save(filePath);

                return true;
            }
            catch (Exception^ ex)
            {
                Console::WriteLine("Ошибка добавления элемента в XML: {0}", ex->Message);
                return false;
            }
        }


    private:
        static void AddManufacturer(Manufacturer^ manufacturer, XmlDocument^ xmlDoc)
        {
            // Ищем корневой элемент (например, <Manufacturers>)
            XmlNode^ root = xmlDoc->DocumentElement;
            root = root->SelectSingleNode("Manufactures");
            if (root == nullptr)
            {
                throw gcnew InvalidOperationException("Корневой элемент отсутствует в XML.");
            }

            // Создаем новый элемент Manufacturer
            XmlElement^ newManufacturer = xmlDoc->CreateElement("Manufacturer");

            // Создаем подэлементы и заполняем их данными
            XmlElement^ codeElement = xmlDoc->CreateElement("ManufacturerCode");
            codeElement->InnerText = manufacturer->ManufacturerCode.ToString();

            XmlElement^ nameElement = xmlDoc->CreateElement("Name");
            nameElement->InnerText = manufacturer->Name;

            XmlElement^ addressElement = xmlDoc->CreateElement("Address");
            addressElement->InnerText = manufacturer->Address;

            // Добавляем подэлементы к элементу Manufacturer
            newManufacturer->AppendChild(codeElement);
            newManufacturer->AppendChild(nameElement);
            newManufacturer->AppendChild(addressElement);

            // Добавляем новый элемент Manufacturer к корневому элементу
            root->AppendChild(newManufacturer);
        }

        static void AddBrand(Brand^ brand, XmlDocument^ xmlDoc)
        {
            // Ищем корневой элемент (например, <Manufacturers>)
            XmlNode^ root = xmlDoc->DocumentElement;
            root = root->SelectSingleNode("Brands");
            if (root == nullptr)
            {
                throw gcnew InvalidOperationException("Корневой элемент отсутствует в XML.");
            }

            // Создаем новый элемент 
            XmlElement^ newBrand = xmlDoc->CreateElement("Brand");

            // Создаем подэлементы и заполняем их данными
            XmlElement^ codeElement = xmlDoc->CreateElement("BrandCode");
            codeElement->InnerText = brand->brandCode.ToString();

            XmlElement^ nameElement = xmlDoc->CreateElement("Name");
            nameElement->InnerText = brand->name;

            XmlElement^ manufacturerCodeElement = xmlDoc->CreateElement("ManufacturerCode");
            manufacturerCodeElement->InnerText = brand->manufacturer->ManufacturerCode.ToString();

            // Добавляем подэлементы к элементу Manufacturer
            newBrand->AppendChild(codeElement);
            newBrand->AppendChild(nameElement);
            newBrand->AppendChild(manufacturerCodeElement);

            // Добавляем новый элемент Manufacturer к корневому элементу
            root->AppendChild(newBrand);
        }

        static void AddOwner(Owner^ owner, XmlDocument^ xmlDoc)
        {
            // Ищем корневой элемент (например, <Owners>)
            XmlNode^ root = xmlDoc->DocumentElement;
            root = root->SelectSingleNode("Owners");
            if (root == nullptr)
            {
                throw gcnew InvalidOperationException("Корневой элемент отсутствует в XML.");
            }

            // Создаем новый элемент Owner
            XmlElement^ newOwner = xmlDoc->CreateElement("Owner");

            // Создаем подэлементы и заполняем их данными
            XmlElement^ codeElement = xmlDoc->CreateElement("OwnerCode");
            codeElement->InnerText = owner->ownerCode.ToString();

            XmlElement^ fullNameElement = xmlDoc->CreateElement("FullName");
            fullNameElement->InnerText = owner->fullName;

            XmlElement^ addressElement = xmlDoc->CreateElement("Address");
            addressElement->InnerText = owner->address;

            // Добавляем подэлементы к элементу Owner
            newOwner->AppendChild(codeElement);
            newOwner->AppendChild(fullNameElement);
            newOwner->AppendChild(addressElement);

            // Добавляем новый элемент Owner к корневому элементу
            root->AppendChild(newOwner);
        }

        static void AddCar(Car^ car, XmlDocument^ xmlDoc)
        {
            // Ищем корневой элемент (например, <Cars>)
            XmlNode^ root = xmlDoc->DocumentElement;
            root = root->SelectSingleNode("Cars");
            if (root == nullptr)
            {
                throw gcnew InvalidOperationException("Корневой элемент отсутствует в XML.");
            }

            // Создаем новый элемент Car
            XmlElement^ newCar = xmlDoc->CreateElement("Car");

            // Создаем подэлементы и заполняем их данными
            XmlElement^ codeElement = xmlDoc->CreateElement("CarCode");
            codeElement->InnerText = car->carCode.ToString();

            XmlElement^ brandCodeElement = xmlDoc->CreateElement("BrandCode");
            brandCodeElement->InnerText = car->brand->brandCode.ToString();

            XmlElement^ chassisNumberElement = xmlDoc->CreateElement("ChassisNumber");
            chassisNumberElement->InnerText = car->chassisNumber;

            XmlElement^ engineNumberElement = xmlDoc->CreateElement("EngineNumber");
            engineNumberElement->InnerText = car->engineNumber;

            // Добавляем подэлементы к элементу Car
            newCar->AppendChild(codeElement);
            newCar->AppendChild(brandCodeElement);
            newCar->AppendChild(chassisNumberElement);
            newCar->AppendChild(engineNumberElement);

            // Добавляем новый элемент Car к корневому элементу
            root->AppendChild(newCar);
        }

        static void AddRegistration(Registration^ registration, XmlDocument^ xmlDoc)
        {
            // Ищем корневой элемент (например, <Registrations>)
            XmlNode^ root = xmlDoc->DocumentElement;
            root = root->SelectSingleNode("Registrations");
            if (root == nullptr)
            {
                throw gcnew InvalidOperationException("Корневой элемент отсутствует в XML.");
            }

            // Создаем новый элемент Registration
            XmlElement^ newRegistration = xmlDoc->CreateElement("Registration");

            // Создаем подэлементы и заполняем их данными
            XmlElement^ codeElement = xmlDoc->CreateElement("RegistrationCode");
            codeElement->InnerText = registration->registrationCode.ToString();

            XmlElement^ ownerCodeElement = xmlDoc->CreateElement("OwnerCode");
            ownerCodeElement->InnerText = registration->owner->ownerCode.ToString();

            XmlElement^ carCodeElement = xmlDoc->CreateElement("CarCode");
            carCodeElement->InnerText = registration->car->carCode.ToString();

            XmlElement^ dateElement = xmlDoc->CreateElement("Date");
            dateElement->InnerText = registration->date;

            // Добавляем подэлементы к элементу Registration
            newRegistration->AppendChild(codeElement);
            newRegistration->AppendChild(ownerCodeElement);
            newRegistration->AppendChild(carCodeElement);
            newRegistration->AppendChild(dateElement);

            // Добавляем новый элемент Registration к корневому элементу
            root->AppendChild(newRegistration);
        }

        public:


        static bool UpdateInXml(String^ filePath, int id, Object^ object)
        {
            try
            {
                fileExists(filePath);

                // Проверяем, существует ли файл
                if (!System::IO::File::Exists(filePath))
                {
                    return false;
                }

                // Загружаем XML-документ
                XmlDocument^ xmlDoc = gcnew XmlDocument();
                xmlDoc->Load(filePath);

                // Обновляем производителя
                if (dynamic_cast<Manufacturer^>(object) != nullptr)
                {
                    UpdateManufacturer(id, (Manufacturer^)object, xmlDoc);
                }
                // Обновляем марку
                else if (dynamic_cast<Brand^>(object) != nullptr)
                {
                    UpdateBrand(id, (Brand^)object, xmlDoc);
                }
                // Обновляем владельца
                else if (dynamic_cast<Owner^>(object) != nullptr)
                {
                    UpdateOwner(id, (Owner^)object, xmlDoc);
                }
                // Обновляем автомобиль
                else if (dynamic_cast<Car^>(object) != nullptr)
                {
                    UpdateCar(id, (Car^)object, xmlDoc);
                }
                // Обновляем регистрацию
                else if (dynamic_cast<Registration^>(object) != nullptr)
                {
                    UpdateRegistration(id, (Registration^)object, xmlDoc);
                }

                // Сохраняем изменения в файл
                xmlDoc->Save(filePath);

                return true;
            }
            catch (Exception^ ex)
            {
                Console::WriteLine("Ошибка обновления элемента в XML: {0}", ex->Message);
                return false;
            }
        }

    private:
        static void UpdateBrand(int id, Brand^ brand, XmlDocument^ xmlDoc) {
            // Ищем элементы Brand
            XmlNodeList^ brandNodes = xmlDoc->GetElementsByTagName("Brand");

            for each (XmlNode ^ node in brandNodes) {
                // Проверяем совпадение ID
                int currentId = Convert::ToInt32(node["BrandCode"]->InnerText);

                if (currentId == id) {
                    // Обновляем данные элемента
                    

                    node["BrandCode"]->InnerText = brand->brandCode.ToString();
                    node["Name"]->InnerText = brand->name;
                    if(brand->manufacturer != nullptr) node["ManufacturerCode"]->InnerText = brand->manufacturer->ManufacturerCode.ToString();
                    break;
                }
            }
        }
        static void UpdateManufacturer(int id, Manufacturer^ manufacturer, XmlDocument^ xmlDoc)
        {
            // Ищем элементы Manufacturer
            XmlNodeList^ manufacturerNodes = xmlDoc->GetElementsByTagName("Manufacturer");

            for each (XmlNode ^ node in manufacturerNodes)
            {
                // Проверяем совпадение ID
                int currentId = Convert::ToInt32(node["ManufacturerCode"]->InnerText);

                if (currentId == id)
                {
                    // Обновляем данные элемента
                    node["ManufacturerCode"]->InnerText = manufacturer->ManufacturerCode.ToString();
                    node["Name"]->InnerText = manufacturer->Name;
                    node["Address"]->InnerText = manufacturer->Address;
                    break;
                }
            }
        }

        static void UpdateOwner(int id, Owner^ owner, XmlDocument^ xmlDoc)
        {
            // Ищем элементы Owner
            XmlNodeList^ ownerNodes = xmlDoc->GetElementsByTagName("Owner");

            for each (XmlNode ^ node in ownerNodes) {
                // Проверяем совпадение ID
                int currentId = Convert::ToInt32(node["OwnerCode"]->InnerText);

                if (currentId == id) {
                    // Обновляем данные элемента
                    node["OwnerCode"]->InnerText = owner->ownerCode.ToString();
                    node["FullName"]->InnerText = owner->fullName;
                    node["Address"]->InnerText = owner->address;
                    break;
                }
            }
        }

        static void UpdateCar(int id, Car^ car, XmlDocument^ xmlDoc)
        {
            // Ищем элементы Car
            XmlNodeList^ carNodes = xmlDoc->GetElementsByTagName("Car");

            for each (XmlNode ^ node in carNodes) {
                // Проверяем совпадение ID
                int currentId = Convert::ToInt32(node["CarCode"]->InnerText);

                if (currentId == id) {
                    // Обновляем данные элемента
                    node["CarCode"]->InnerText = car->carCode.ToString();
                    node["BrandCode"]->InnerText = car->brand->brandCode.ToString();
                    node["ChassisNumber"]->InnerText = car->chassisNumber;
                    node["EngineNumber"]->InnerText = car->engineNumber;
                    break;
                }
            }
        }

        static void UpdateRegistration(int id, Registration^ registration, XmlDocument^ xmlDoc)
        {
            // Ищем элементы Registration
            XmlNodeList^ registrationNodes = xmlDoc->GetElementsByTagName("Registration");

            for each (XmlNode ^ node in registrationNodes) {
                // Проверяем совпадение ID
                int currentId = Convert::ToInt32(node["RegistrationCode"]->InnerText);

                if (currentId == id) {
                    // Обновляем данные элемента
                    node["RegistrationCode"]->InnerText = registration->registrationCode.ToString();
                    node["OwnerCode"]->InnerText = registration->owner->ownerCode.ToString();
                    node["CarCode"]->InnerText = registration->car->carCode.ToString();
                    node["Date"]->InnerText = registration->date;
                    break;
                }
            }
        }

    public:

        static Object^ findElementByCode(int id, TableType tableType) {
            switch (tableType) {
            case TableType::Manufacturers:
                for each (Manufacturer ^ var in Manufacturer::manufacturers)
                {
                    if (var->ManufacturerCode == id) return var;
                }
                return gcnew Manufacturer();
                break;
            case TableType::Brands:
                for each (Brand ^ var in Brand::brands)
                {
                    if (var->brandCode == id) return var;
                }
                return gcnew Brand();
                break;
            case TableType::Owners:
                for each (Owner ^ var in Owner::owners)
                {
                    if (var->ownerCode == id) return var;
                }
                return gcnew Owner();
                break;
            case TableType::Cars:
                for each (Car ^ var in Car::cars)
                {
                    if (var->carCode == id) return var;
                }
                return gcnew Car();
                break;
            case TableType::Registrations:
                for each (Registration ^ var in Registration::registrations)
                {
                    if (var->registrationCode == id) return var;
                }
                return gcnew Registration();
                break;
            }
            return nullptr;
        }


};

