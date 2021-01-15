#include "MenuController.h"
#include "OperationDay.h"
#include "Deposit.h"
#include "Client.h"
#include "Date.h"

int main()
{
	MenuController* m = new MenuController;
	m->menu();
	delete m;
	return 0;
}