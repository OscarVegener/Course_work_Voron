#include "MenuController.h"

int main()
{
	MenuController* m = new MenuController;
	m->menu();
	delete m;
	return 0;
}