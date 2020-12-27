#include <iostream>
#include "Date.h"
#include "Person.h"
#include "Client.h"
#include "Deposit.h"
#include "OperationDay.h"
#include "MenuController.h"

int main()
{
	MenuController* m = new MenuController;
	m->menu();
	delete m;
	return 0;
}