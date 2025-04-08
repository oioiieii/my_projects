#include "pch.h"
#include "Intro.h"

void TP_Project::Intro::Finish_Path_0(Object^ sender) {
	ShipCargo^ ship = dynamic_cast<ShipCargo^>(sender);
	ship->RaiseRequestValidation(0);
}
void TP_Project::Intro::Finish_Path_1(Object^ sender) {
	ShipCargo^ ship = dynamic_cast<ShipCargo^>(sender);
	ship->RaiseShipArrivedToPort(0);
}
void TP_Project::Intro::Finish_Path_2(Object^ sender) {
	ShipCargo^ ship = dynamic_cast<ShipCargo^>(sender);
	//ћы выплыли к выходу из авкватории и присваиваем другой  путь
	ship->CurrentPath = gcnew Path(3);
}

void TP_Project::Intro::Finish_Path_3(Object^ sender) {
	ShipCargo^ ship = dynamic_cast<ShipCargo^>(sender);
	delete ship;
}

void TP_Project::Intro::Finish_Path_4(Object^ sender) {
	Ship^ ship = dynamic_cast<Ship^>(sender);
	//«апрос порту на подступ к причалу
	ship->RaiseRequestValidation(1);
}
void TP_Project::Intro::Finish_Path_5(Object^ sender) {
	Ship^ ship = dynamic_cast<Ship^>(sender);
	//√оворим причалу что корабль прибыл
	ship->RaiseShipArrivedToPort(1);
}
void TP_Project::Intro::Finish_Path_6(Object^ sender) {
	Ship^ ship = dynamic_cast<Ship^>(sender);
	//√оворим причалу что корабль прибыл
	ship->RaiseShipArrivedToPort(2);
}

void TP_Project::Intro::Finish_Path_7(Object^ sender) {
	Ship^ ship = dynamic_cast<Ship^>(sender);
	ship->RaiseShipLeavePort(1);
}
void TP_Project::Intro::Finish_Path_8(Object^ sender) {
	Ship^ ship = dynamic_cast<Ship^>(sender);
	ship->RaiseShipLeavePort(2);
}
void TP_Project::Intro::Finish_Path_9(Object^ sender) {
	Ship^ ship = dynamic_cast<Ship^>(sender);
	delete ship;
}