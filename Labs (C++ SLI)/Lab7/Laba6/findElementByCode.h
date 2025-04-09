#pragma once
#include "classes.h"
namespace Laba6{
static ref class findElementByCodeClass
{
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

}
