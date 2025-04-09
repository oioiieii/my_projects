#pragma once
#include <string>;
#using <mscorlib.dll>
using namespace System;

ref class organization abstract
{
private:
	//Поля
	String^ _name;
	String^ _INN; 
	int _balans;

public:
	//Свойства
	property String^ name {
		void set(String^ value) {
			_name = value;
		}
		String^ get() {
			return _name;
		}
	}
	property String^ INN {
		void set(String^ value) {
			_INN = value;
			
		}
		String^ get() {
			return _INN;
		}
	}
	property int balans {
		void set(int value) {
			_balans = value;
		}
		int get() {
			return _balans;
		}
	}

	//Методы
	organization(String^ __name, String^ __INN, int __balans) {
		name = __name;
		INN = __INN;
		balans = __balans;
	}

	void getInfo() {
		Console::WriteLine("Наименование организации: '{0}', ИНН: '{1}.'", name, INN);
		Console::WriteLine("Текущее состояние: '{0}' тысяч рублей.", balans);
	}
};

ref class gasCompany : organization {
private:
	int _gasValue;
	int _oilValue;

	int _extractionGasPerDat;
	int _extractionOilPerDat;

	int _costOil;
	int _costGas;

public:
	property int gasValue {
		void set(int value) {
			_gasValue = value;
		}
		int get() {
			return _gasValue;
		}
	}
	property int oilValue {
		void set(int value) {
			_oilValue = value;
		}
		int get() {
			return _oilValue;
		}
	}

	property int extractionGasPerDay {
		void set(int value) {
			_extractionGasPerDat = value;
		}
		int get() {
			return _extractionGasPerDat;
		}
	}
	property int extractionOilPerDay {
		void set(int value) {
			_extractionOilPerDat = value;
		}
		int get() {
			return _extractionOilPerDat;
		}
	}
	
	property int costOil {
		void set(int value) {
			_costOil = value;
		}
		int get() {
			return _costOil;
		}
	}
	property int costGas {
		void set(int value) {
			_costGas = value;
		}
		int get() {
			return _costGas;
		}
	}
	
	//Методы
	gasCompany(String^ __name, String^ __INN, int __balans, int __extractionGasPerDat, int __extractionOilPerDat, int __costOil, int __costGas) :organization(__name, __INN, __balans) {
		gasValue = 0;
		oilValue = 0;

		extractionGasPerDay = __extractionGasPerDat;
		extractionOilPerDay = __extractionOilPerDat;

		costOil = __costOil;
		costGas = __costGas;
	}

	void Extraction() {
		//Погрешность
		Random^ rnd = gcnew Random();

		int madeGas = extractionGasPerDay + rnd->Next(-20, 21);
		int madeOil = extractionOilPerDay + rnd->Next(-20, 21);

		gasValue += madeGas;
		oilValue += madeOil;

		Console::WriteLine("Нефтегазовая компания {0}: \nДобыто газа: {1} л., добыто нефти: {2} л.\n",name, madeGas, madeOil);
	}

	//Продажа товара
	void Export() {
		int soldGas = gasValue * costGas;
		int soldOil = oilValue * costOil;

		balans += soldGas + soldOil;

		gasValue = 0;
		oilValue = 0;
	}
};

ref class insuranceCompany : organization {
private:
	int _numClients;
	int _avgNumInsuredEventsPerDay;
	int _avgNumNewClientsPerDay;
	int _costInsure;
	int _costCompensation;

public:
	property int costInsure {
		void set(int value) {
			_costInsure = value;
		}
		int get() {
			return _costInsure;
		}
	}
	property int costCompensation {
		void set(int value) {
			_costCompensation = value;
		}
		int get() {
			return _costCompensation;
		}
	}
	property int numClients {
		void set(int value) {
			_numClients = value;
		}
		int get() {
			return _numClients;
		}
	}
	property int avgNumInsuredEventsPerDay {
		void set(int value) {
			_avgNumInsuredEventsPerDay = value;
		}
		int get() {
			return _avgNumInsuredEventsPerDay;
		}
	}
	property int avgNumNewClientsPerDay {
		void set(int value) {
			_avgNumNewClientsPerDay = value;
		}
		int get() {
			return _avgNumNewClientsPerDay;
		}
	}
	
	insuranceCompany(String^ __name, String^ __INN, int __balans, int __numClients, int __avgNumInsuredEventsPerDay, int __avgNumNewClientsPerDay, int __costInsure, int __costCompensation):organization(__name, __INN, __balans) {
		numClients = __numClients;
		 avgNumInsuredEventsPerDay = __avgNumInsuredEventsPerDay;
		 avgNumNewClientsPerDay = __avgNumNewClientsPerDay;
		 costInsure = __costInsure;
		 costCompensation = __costCompensation;
	}

	void Service() {
		Random^ rnd = gcnew Random();

		int newClinets = avgNumNewClientsPerDay + rnd->Next(-avgNumNewClientsPerDay, avgNumNewClientsPerDay);
		int insuredEvents = avgNumInsuredEventsPerDay + rnd->Next(-avgNumInsuredEventsPerDay, 0);

		numClients += newClinets - insuredEvents;
		balans += costInsure * newClinets - costCompensation * insuredEvents;

		Console::WriteLine("Страховая компания {0}: \nПодписано новых клиентов: {1}, обслужено страховых случаев: {2}.\n", name, newClinets, insuredEvents);
	}

	void CollectingPayment() {
		balans += costInsure * numClients;
	}
};

ref class factory : organization {
private:
	int _stockDetails;
	int _productionDetailsPerDay;
	int _valueForSale;
	int _costDetail;
	
public:
	//Свойства
	property int stockDetails {
		void set(int value) {
			if (value >= valueForSale) {
				//Продаем
				value -= valueForSale;
				balans += valueForSale * costDetail;
				Console::WriteLine(", выручка за продажу деталей : {0} рублей.", valueForSale * costDetail);
			}
			_stockDetails = value;
		}
		int get() {
			return _stockDetails;
		}
	}
	property int valueForSale {
		void set(int value) {
			_valueForSale = value;
		}
		int get() {
			return _valueForSale;
		}
	}
	property int productionDetailsPerDay {
		void set(int value) {
			_productionDetailsPerDay = value;
		}
		int get() {
			return _productionDetailsPerDay;
		}
	}
	property int costDetail {
		void set(int value) {
			_costDetail = value;
		}
		int get() {
			return _costDetail;
		}
	}

	
	//Метод произведения деталей деталей
	void Production() {
		//Погрешность
		Random^ rnd = gcnew Random();
		
		int newDetails = productionDetailsPerDay + rnd->Next(-100, 100);
		Console::Write("Завод '{0}': \nПроизведено деталей : {1} шт.", name, newDetails);
		stockDetails += newDetails;

	}

	//Конструктор
	factory(String^ __name, String^ __INN, int __balans, int __valueForSale, int __productionDetailsPerDay, int __costDetail) : organization(__name, __INN, __balans){
		valueForSale = __valueForSale;
		stockDetails = 0;
		productionDetailsPerDay = __productionDetailsPerDay;
		costDetail = __costDetail;
	}
};