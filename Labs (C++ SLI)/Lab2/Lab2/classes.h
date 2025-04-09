#pragma once
#include <iostream>

#include <cstdlib>
#include <ctime> 
using namespace std;

//ИНТЕРФЕЙСЫ
class IPopulated {
	public: virtual void output_population() = 0;
};
class ISpatial {
	public: virtual void output_area() = 0;
};
class IMutable {
	public: virtual void live() = 0;
};


//КЛАССЫ
class APlace: public IPopulated, public ISpatial
{
protected:
	string name;

public: 
	virtual void output_name() = 0;

	// Установка начальных данных для объектов-наследников
	APlace(string name_) : name(name_){}
};

class City : public APlace, public IMutable
{
protected:
	int _population;
	int _area;

public:
	int population() {
		return _population;
	}
	int area() {
		return _area;
	}

	// Конструктор для инициализации города
	City(string name_, int population_, int area_)
		: APlace(name_), _population(population_), _area(area_) {}

	//Переопределение методов абстрактного класса
	void output_name() override{
		cout << "Название города: " << name << endl;
	}

	//Реализация интерфейсов
	void live() override{
		int newPeople = rand() % 5001 + 5000;
		_population += newPeople;
		if (_population > 20000) {
			cout << "Город стал мегаполисом\n";
		}
		_area += newPeople/10;
		cout << "В городе под названием '" << name << "' увеличилось количество населения на " << newPeople << "ч., а территория на " << newPeople / 10 << "га.\n";
	}

	void output_population() override {
		cout << "В этом городе проживает " << population() << " человек. \n";
	}

	void output_area() override {
		cout << "Площадь этого города занимает " << area() << " га.\n";
	}
};

class MegaCity : public City {
public:
	MegaCity(string name_, int population_, int area_)
		: City(name_, population_, area_) {}

	void output_name() override {
		cout << "Название мегаполиса: " << name << endl;
	}

	void live() override {
		int newPeople = rand() % 30001 + 10000;
		_population += newPeople;
		_area += newPeople / 100;
		cout << "В мегаполисе под названием '" << name << "' увеличилось количество населения на " << newPeople << "ч., а территория на " << newPeople / 10 << "га.\n";
	}
	
	void output_population() override {
		cout << "В этом мегаполисе проживает " << population() << " человек. \n";
	}

	void output_area() override {
		cout << "Площадь этого мегаполиса занимает " << area() << " га.\n";
	}


};

class Region : public APlace 
{
public:
	City* cities[10];
	int n;
	
	Region(string name_, City* cities_[], int n_) : APlace(name_), n(n_)
	{
		for (int i = 0; i < n; i++) {
			cities[i] = cities_[i]; // Копируем указатели
		}
	}

	//Переопределение методов абстрактного класса
	void output_name() override {
		cout << "Название области: " << name << endl;
	}


	//Реализация интерфейсов
	void output_population() override {
		int counter = 0;
		for (int i = 0; i < n; i++) {
			counter += (*cities[i]).population();
		}
		cout << "В этой области проживает " << counter << " человек.\n";
	}

	void output_area() override {
		int counter = 0;
		for (int i = 0; i < n; i++) {
			counter += (*cities[i]).area();
		}
		cout << "Площадь этой области занимает " << counter << " га.\n";
	}
};


//РАСШИРЕНИЕ
class Person : public IMutable 
{
public:
	int age;
	string name;

	Person(string name_, int age_) : age(age_), name(name_) {}

	void live() override {
		age++;
		cout << "Человек по имени " << name << "прожил еще 1 год.\n";
	}
};
