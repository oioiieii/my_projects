#include "Machine.h"
#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public delegate void CoffeeInCupChangedHandler(double value, bool haveMilk);

ref class Cup
{
	Point Location_;

	//Заполненность кружки
	double Coffee_;

	bool haveMilk = false;

	//Метод, срабатываемый на событие приготовления кофе,
	//а также осуществляющий заполнение кружки
	void OnMakingCoffee() {
		Coffee += 5;
	}
	
	//Метод, срабатываемый на событие добавления молока,
	//а также присваивающий полю, отвечающему за наличие молока истинное значение
	void OnAddingMilk(int value) {
		haveMilk = true;
	}

public:
	event CoffeeInCupChangedHandler^ CoffeeInCupChanged;

	property double Coffee {
		void set(double value) {
			Coffee_ = value;
			CoffeeInCupChanged(value, haveMilk);
			//Вызов события отрисовки заполнения чашки
		}
		double get() {
			return Coffee_;
		}
	}

	property Point Location{
		Point get() {
			return Location_;
		}
	}

	//Конструктор класса чашка
	Cup(CoffeeMachine^ machine) {
		Coffee = 0;
		machine->MakingCoffee += gcnew MakingCoffeeHandler(this, &Cup::OnMakingCoffee);
		
		//Временно
		Location_ = Point(196, 210);

		ImprovedCoffeeMachine::AddingMilk += gcnew AddingMilkHandler(this, &Cup::OnAddingMilk);
	}
};

