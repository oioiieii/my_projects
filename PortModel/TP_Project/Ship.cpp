#include "pch.h"
#include "Ship.h"


void Ship::RaiseRequestValidation(int i) {
	//Подписываемся на ответ
	if (i == 0) Port::ShipCanMoveToPort0 += ValidationAvaible;
	else if (i == 1) Port::ShipCanMoveToPort1 += ValidationAvaible, Port::ShipCanMoveToPort2 += ValidationAvaible;
	//Вызываем событие
	Ship::RequestValidation(i);
}

void Ship::RaiseShipLeavePort(int i)
{
	ShipLeavePort(i);
	CurrentPath = gcnew Path(9);
}

void Ship::OnValidationAvaible(int i) {
	//отписываемся и меняем путь
	if (i == 0) Port::ShipCanMoveToPort0 -= ValidationAvaible, CurrentPath = gcnew Path(1);
	else {
		Port::ShipCanMoveToPort1 -= ValidationAvaible;
		Port::ShipCanMoveToPort2 -= ValidationAvaible;
		if (i == 1)  CurrentPath = gcnew Path(5);
		else if (i == 2) CurrentPath = gcnew Path(6);
	}
}

void Ship::OnShipCanSail(int i)
{
	if (i == 0) Port::ShipCanSailFromPort0 -= ShipCanSail, CurrentPath = gcnew Path(2), ShipLeavePort(0);
	else if (i == 1) Port::ShipCanSailFromPort1 -= ShipCanSail, CurrentPath = gcnew Path(7);
	else if (i == 2) Port::ShipCanSailFromPort2 -= ShipCanSail, CurrentPath = gcnew Path(8);
}

void Ship::RaiseShipArrivedToPort(int i)
{
	ShipArrivedToPort(i, this);
	if (i==1)Port::ShipCanSailFromPort1 += gcnew ShipSailsFromPortHandler(this, &ShipCargo::OnShipCanSail);
	else if (i==2) Port::ShipCanSailFromPort2 += gcnew ShipSailsFromPortHandler(this, &ShipCargo::OnShipCanSail);
}

void ShipCargo::RaiseShipArrivedToPort(int i)
{
	direction->angle = 0;
	RotatePictureBox(0);
	ShipArrivedToPort(i, this);
	Port::ShipCanSailFromPort0 += gcnew ShipSailsFromPortHandler(this, &ShipCargo::OnShipCanSail);
}

