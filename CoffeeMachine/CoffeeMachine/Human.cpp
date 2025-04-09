#include "pch.h"
#include "Human.h"

//ћетод осуществл€ющий подписку кофемашины на событи€ человека
void CoffeeMachine::SubscribeMachineOnHumanEvents() {
	Human::FillTank += gcnew FillTankHandler(this, &CoffeeMachine::OnFillTank);
	Human::TurnOnMachine += gcnew TurnOnMachineHandler(this, &CoffeeMachine::TurnOn);
}