#include <iostream>
#include <string>
#include "Menu.h"
#include "BankControl.h"
using namespace std;
int main()
{
	Menu::welcomeScreen();
	BankControl::loginScreen();

	return 0;
}
