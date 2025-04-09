using namespace System;
using namespace System::Windows::Forms;

#pragma once

//Делегаты
public delegate void IndicatorChangedHandler(bool value);
public delegate void ResourseChangedHandler(double value);
public delegate void MakingCoffeeHandler();
public delegate void EndMakingCoffeeHandler();
public delegate void EmptyingTankHandler(int value);

ref class CoffeeMachine
{
protected:
	//Заполненость баков в процентах
	double Water_;
	double Coffee_;

	bool IndicatorWater_;
	bool IndicatorCoffee_;

	bool Enabled_;
	Timer timer;
	
	//Процесс создания кофе
	void TimerMakingCoffee_Tick(Object^ sender, EventArgs^ e) {
		if (i == 20) Enabled = false;//вызываем событие кофе готово
		else if (IndicatorCoffee && IndicatorWater) {
			MakingCoffee();
			i++;
		}
	}

	void SubscribeMachineOnHumanEvents();

	int i;

	//Метод, срабатываемый на событие приготовления кофе, 
	// а также осуществляющий убавление ресурсов машины 
	virtual void OnMakingCoffee() {
		//Из баков забираются ресурсы
		Water -= 1;
		Coffee -= 0.5;
	}

	//Метод, срабатываемый на событие заполнения баков,
	// а также присваивающий полям, отвечающим за ресурсы баков число 100  
	virtual void OnFillTank(int num) {
		if (num == 1) Water = 100;
		else if (num == 2) Coffee = 100;
	}

	//Метод, включающий приготовление кофе
	void TurnOn() {
		if (IndicatorCoffee != false && IndicatorWater != false) Enabled = true;
	}
public:
	//События для отрисовки
	event IndicatorChangedHandler^ IndicatorCoffeeChanged;
	event IndicatorChangedHandler^ IndicatorWaterChanged;
	event IndicatorChangedHandler^ IndicatorCookingChanged;
	event ResourseChangedHandler^ WaterChanged;
	event ResourseChangedHandler^ CoffeeChanged;

	//События
	event MakingCoffeeHandler^ MakingCoffee;
	static event EndMakingCoffeeHandler^ EndMakingCoffee;
	static event EmptyingTankHandler^ EmptyingTank;

	property double Water {
		void set(double value) {
			if (value >= 0 && value <= 100) {
				Water_ = value;
				WaterChanged(value);
				if (Water_ == 0) IndicatorWater = false;
				else IndicatorWater = true;
			}
		}
		double get(){
			return Water_;
		}
	}
	property double Coffee {
		void set(double value) {
			if (value >= 0 && value <= 100) {
				Coffee_ = value;
				CoffeeChanged(value);
				if (Coffee_ == 0) IndicatorCoffee = false;
				else IndicatorCoffee = true;
			}
		}
		double get(){
			return Coffee_;
		}
	}

	property bool Enabled {
		void set(bool value) {
			Enabled_ = value;
			timer.Enabled = value;
			i = 0;
			if (!value) EndMakingCoffee();
			IndicatorCookingChanged(value);
		}
		bool get() {
			return Enabled_;
		}
	}
	property bool IndicatorCoffee {
		void set(bool value) {
			IndicatorCoffee_ = value;
			IndicatorCoffeeChanged(value);//Смена цвета индиктора
			if (value == false) EmptyingTank(2);//Вызываем событие чтобы пополнили
		}
		bool get() {
			return IndicatorCoffee_;
		}
	}
	property bool IndicatorWater {
		void set(bool value) {
			IndicatorWater_ = value;
			IndicatorWaterChanged(value);//Смена цвета индиктора
			if (value == false) EmptyingTank(1);//Вызываем событие чтобы пополнили
		}
		bool get() {
			return IndicatorWater_;
		}
	}

	//Конструктор класса кофемашины
	CoffeeMachine() {
		Water = 100;
		Coffee = 100;

		timer.Interval = 100;
		timer.Tick += gcnew System::EventHandler(this,	&CoffeeMachine::TimerMakingCoffee_Tick);

		MakingCoffee += gcnew MakingCoffeeHandler(this, &CoffeeMachine::OnMakingCoffee);
		SubscribeMachineOnHumanEvents();
	}

	//Деструктор класса кофемашины
	~CoffeeMachine() {
		// Отключаем таймер
		timer.Enabled = false;

		// Отписываемся от событий
		timer.Tick -= gcnew System::EventHandler(this, &CoffeeMachine::TimerMakingCoffee_Tick);
		MakingCoffee -= gcnew MakingCoffeeHandler(this, &CoffeeMachine::OnMakingCoffee);
	}  
};


public delegate void AddingMilkHandler(int value);

ref class ImprovedCoffeeMachine : public CoffeeMachine {
private:
	double Milk_;
	bool IndicatorMilk_;

protected:
	//Переопределение метода, срабатываемого на событие приготовления кофе
	virtual void OnMakingCoffee() override {
		//Из баков забираются ресурсы
		Water -= 1;
		Coffee -= 0.5;
		//Добавлено
		if (i >= 10) Milk -= 1, AddingMilk(i);
	}

	//Переопределение метода, срабатываемого на событие заполнения баков
	virtual void OnFillTank(int num) override {
		if (num == 1) Water = 100;
		else if (num == 2) Coffee = 100;
		else if (num == 3) Milk = 100;
	}

public:
	event IndicatorChangedHandler^ IndicatorMilkChanged;
	event ResourseChangedHandler^ MilkChanged;

	//Cтатические событие добавление молока
	static event AddingMilkHandler^ AddingMilk;

	property double Milk {
		void set(double value) {
			if (value >= 0 && value <= 100) {
				Milk_ = value;
				MilkChanged(value);
				if (Milk_ == 0) IndicatorMilk = false;
				else IndicatorMilk = true;
			}
		}
		double get() {
			return Milk_;
		}
	}
	property bool IndicatorMilk {
		void set(bool value) {
			IndicatorMilk_ = value;
			IndicatorMilkChanged(value);//Смена цвета индиктора
			if (value == false) EmptyingTank(3);//Вызываем событие чтобы пополнили
		}
		bool get() {
			return IndicatorMilk_;
		}
	}

	//Конструктор класса улучшенной кофемашины
	ImprovedCoffeeMachine() : CoffeeMachine() {
		Milk = 100;
	}
};