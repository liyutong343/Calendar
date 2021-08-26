#include <iostream>
#include "Month.h"
#include "CalendarMenu.h"
using namespace std;

int main()
{
	int option;
	while (true) {
		system("cls");
		CalendarMenu calmenu;
		calmenu.show();
		cin >> option;
		switch (option) {
		case 0:
			calmenu.exit_system();
			system("pause");
			break;
		case 1:
			calmenu.display_month();
			system("pause");
			break;
		case 2:
			calmenu.display_year();
			system("pause");
			break;
		default:
			cout << "Please check your input!" << endl;
			cout << "It should be 1, 2 or 0." << endl;
			system("pause");
			break;
		}

		

	}
}


