#pragma once
#include <iostream>
#include "Machine.h"
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public delegate void HandMovingHandler(int status, Point^ loc);
public delegate void EndedMovingHandler(int status);
public delegate void FillTankHandler(int num);
public delegate void TurnOnMachineHandler();

ref class Human
{
	Point^ Loc;
	Timer^ timer;
	Timer^ constantTimer;
	int timeAction;
	int status;
	array<bool>^ NeedRefillTanks;

	//Метод, осущствляющий передвижение рук в сторону цели (точки)
	void MovingHand(Point goal) {
		int step = 10;
		
		double dx = goal.X - Loc->X;
		double dy = goal.Y - Loc->Y;

		// Вычисляем угол между текущим местоположением и целью
		double angle = atan2(dy, dx);

		// Двигаем текущее местоположение на 10 пикселей в сторону цели
		Loc = Point(Loc->X + step * cos(angle), Loc->Y + step * sin(angle));

		HandMoving(status, Loc);

		//Добавить проверку на достижение точки, в случае успеха меняем состояние на +1
		double distance = sqrt(dx * dx + dy * dy);
		if (distance <= step) {
			Loc = goal;
			HandEndedMoving(status);//Вызываем событие рука закончила движение передаем статус (на форме меняется изображение руки, создается кружка, тут меняется некст точка и продолжаем двигаться) в обработчиках в зависимости от статуса будет меняться по разному
			status++;
		}
	}

	//Метод, срабатывающий по достижению руки своей цели (точки)
	void OnHandEndedMoving(int value) {
		switch (value)
		{
		case(1):
			Loc = Point(Loc->X + 43 /*- 34 + 134 + 14 - 64*/, Loc->Y - 72 /* - 68 + 54 + 5 - 68*/);
			break;
		case(2):
			CoffeeMachine::EndMakingCoffee += gcnew EndMakingCoffeeHandler(this, &Human::OnEndMakingCoffee);
			TurnOnMachine();
			timer->Enabled = false;
			Loc = Point(Loc->X - 14 + 64, Loc->Y - 5 + 68);
			break;
		case(4):
			//Если надо заполнить бак, то мы это делаем
			timer->Enabled = false;
			if (CheckingNeedRefill()) {
				HandEndedMoving(5);
				RefillTank();
				Loc = Point(583 + 52, 382 + 52);
			}
			else status = -1;
			//Пауза на 2 секунды
			System::Threading::Thread::Sleep(2000);
			break;
		case(14):
		case(8):
			System::Threading::Thread::Sleep(2000);
			break;
		case(10):
			FillTank(1);
			NeedRefillTanks[0] = 0;
			if (CheckingNeedRefill()) RefillTank();
			break;
		case(11):
			status = -1;
			break;
		case(16):
			FillTank(2);
			NeedRefillTanks[1] = 0;
			if (CheckingNeedRefill()) RefillTank();
			else status = 10;
			break;
		case(19):
			Loc = Point(Loc->X - 3, Loc->Y);
			break;
		case(20):
			System::Threading::Thread::Sleep(2000);
			break;
		case(22):
			FillTank(3);
			NeedRefillTanks[2] = 0;
			status = 10;
			break;
		default:
			break;
		}
	}

	//Метод, проверяющий необходимость перезаполнения баков	
	bool CheckingNeedRefill() {
		bool flag = false;
		for (int i = 0; i < NeedRefillTanks->Length; i++) {
			if (NeedRefillTanks[i] == true) {
				flag = true;
				break;
			}
		}
		return flag;
	}

	//Метод, срабатывающий по окончанию приготовления кофе
	// а также позволяющий человеку продолжить движение
	void OnEndMakingCoffee() {
		timer->Enabled = true;
	}

	//Метод, вызывающий метод MoovingHand, в зависимости от статуса человека
	void TimerMovingHand_Tick(Object^ sender, EventArgs^ e) {
		switch (status)
		{
		case(1):
			MovingHand(Point(419, 501));
			break;
		case(2):
			MovingHand(Point(543, 431));
			break;
		case(3):
			MovingHand(Point(519, 486));
			break;
		case(4):
			MovingHand(Point(575, 650));
			break;
		//Пополнение воды
		case(6):
			MovingHand(Point(264 + 188 / 2 + 10, 143 + 166 / 2 + 20));
			break;
		case(7):
			MovingHand(Point(264 + 94, 143 - 70));
			break;
		case(8):
			MovingHand(Point(264 + 94 + 500, 143 - 80));
			break;
		case(9):
			MovingHand(Point(264 + 94, 143 - 70));
			break;
		case(10):
			MovingHand(Point(264 + 190 / 2 + 6, 143 + 166 / 2 + 12));
			break;
		case(11):
			MovingHand(Point(583 + 52, 382 + 52));
			break;
		//Пополнение кофе
		case(12):
			MovingHand(Point(454 + 124 / 2 + 10, 143 + 166 / 2 + 20));
			break;
		case(13):
			MovingHand(Point(454 + 124 / 2 + 10, 143 - 166 / 2 - 20));
			break;
		case(14):
			MovingHand(Point(264 + 94 + 500, 143 - 80));
			break;
		case(15):
			MovingHand(Point(454 + 124 / 2 + 15, 143 - 166 / 2 - 20));
			break;
		case(16):
			MovingHand(Point(454 + 124 / 2 + 10, 143 + 166 / 2 + 18));
			break;
		//Пополнение молока
		case(18):
			MovingHand(Point(206 + 33 + 10, 235 + 68 + 24));
			break;
		case(19):
			MovingHand(Point(206 + 33 + 10, 235 + 68 + 24 - 50));
			break;
		case(20):
			MovingHand(Point(-40, 235 + 68 + 24 - 50));
			break;
		case(21):
			MovingHand(Point(206 + 33 + 10, 235 + 68 + 24 - 50));
			break;
		case(22):
			MovingHand(Point(206 + 33 + 10, 235 + 68 + 24));
			break;
		default:
			break;
		}
	}
	
	//Метод, срабатываемый на событие опустошения баков
	void OnEmptyingTank(int value) {
		NeedRefillTanks[value - 1] = true;
	}

	//Метод осуществляющий случайный вызов приготовления кофе в интервале от 30 - 15 секунд
	void RandomRaisePutCoffee(Object^ sender, EventArgs^ e) {
		//Если случайное число == 0 вызываем putCoffee
		if (timeAction == 0) {
			PutCup();
			//Случайное число записывается в timeAction;
			srand(time(0));
			timeAction = 1000 * (rand() % (30 - 15 + 1) + 15);
		}
		else timeAction -= constantTimer->Interval;
	}

	//Метод, устанавливающий статус человека для перезаполнения баков
	void RefillTank() {
		//Устанавливаем статус
		if (NeedRefillTanks[0]) status = 5;
		else if (NeedRefillTanks[1]) status = 11;
		else if (NeedRefillTanks[2]) HandEndedMoving(17), status = 17;
		timer->Enabled = true;
	}

public: 
	event HandMovingHandler^ HandMoving;
	event EndedMovingHandler^ HandEndedMoving;

	static event FillTankHandler^ FillTank;
	static event  TurnOnMachineHandler^ TurnOnMachine;

	//Метод, присваивающий статус человеку для установления чашки
	void PutCup() {
		//Проверяем не занят ли человек
		if (status == 0) {
			HandEndedMoving(0);
			Loc = Point(622, 511);
			timer->Enabled = true;
			status = 1;
		}
	}

	//Метот, сбрасывающий статус человека
	void ResetStatus() {
		status = 0;
		NeedRefillTanks = gcnew array<bool>{0, 0, 0};
	}

	//Конструктор класса человек
	Human(CoffeeMachine^ machine) {
		Loc = Point(622, 511);
		timer = gcnew Timer();
		timer->Tick += gcnew System::EventHandler(this, &Human::TimerMovingHand_Tick);
		constantTimer = gcnew Timer();
		timeAction = 0;
		constantTimer->Enabled = true;
		constantTimer->Tick += gcnew System::EventHandler(this, &Human::RandomRaisePutCoffee);
		HandEndedMoving += gcnew EndedMovingHandler(this, &Human::OnHandEndedMoving);
		NeedRefillTanks = gcnew array<bool>{0, 0, 0};
		machine->EmptyingTank += gcnew EmptyingTankHandler(this, &Human::OnEmptyingTank);
	}

	//Дестркутор класса чловек
	~Human(){
		delete timer;
	}
};