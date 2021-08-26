#include "Month.h"

#include <iostream>
#include <iomanip>
using namespace std;

Month::Month()
{

}

Month::Month(int y, int m)
{
	year = y;
	month = m;
	leap_year = set_leap_year(y);
	days = set_days(leap_year, m);
	first_day_of_week = set_first_day_of_week(y, m);
	int j = 1;
	for (int i = first_day_of_week; i < first_day_of_week + days; i++) {
		cal[i] = j;
		j++;
	}
}

bool Month::set_leap_year(int y)
{
	if (y % 4 == 0){
		if (y % 100 == 0){
			if (y % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

int Month::set_days(bool ly, int m)
{
	switch (m) {
	case 1:
		return 31;
		break;
	case 2:
		if (ly)
			return 29;
		else
			return 28;
		break;
	case 3:
		return 31;
		break;
	case 4:
		return 30;
		break;
	case 5:
		return 31;
		break;
	case 6:
		return 30;
		break;
	case 7:
		return 31;
		break;
	case 8:
		return 31;
		break;
	case 9:
		return 30;
		break;
	case 10:
		return 31;
		break;
	case 11:
		return 30;
		break;
	default:
		return 31;
		break;


	}

}

int Month::set_first_day_of_week(int y, int m)
{
	int d = 0;                         
	for (int i = 0; i < y; i++){
		if (set_leap_year(y))
			d += 366;
		else
			d += 365;
	}
	for (int i = 1; i < m; i++) {
		d += set_days(set_leap_year(y), i);
	}
	return d % 7;
}

void Month::show()
{
	int count = 0;
	switch (month) {
	case 1:
		cout << setw(20) << "January" << ' ' << year << endl;
		break;
	case 2:
		cout << setw(20) << "February" << ' ' << year << endl;
		break;
	case 3:
		cout << setw(20) << "March" << ' ' << year << endl;
		break;
	case 4:
		cout << setw(20) << "April" << ' ' << year << endl;
		break;
	case 5:
		cout << setw(20) << "May" << ' ' << year << endl;
		break;
	case 6:
		cout << setw(20) << "June" << ' ' << year << endl;
		break;
	case 7:
		cout << setw(20) << "July" << ' ' << year << endl;
		break;
	case 8:
		cout << setw(20) << "August" << ' ' << year << endl;
		break;
	case 9:
		cout << setw(20) << "September" << ' ' << year << endl;
		break;
	case 10:
		cout << setw(20) << "October" << ' ' << year << endl;
		break;
	case 11:
		cout << setw(20) << "November" << ' ' << year << endl;
		break;
	default:
		cout << setw(20) << "December" << ' ' << year << endl;
		break;
	}
		
	cout << setw(5) << "Son." << setw(5) << "Mon." << setw(5) << "Tue." << setw(5) 
		<< "Wed." << setw(5) << "Thu." << setw(5) << "Fri." << setw(5) << "Sat." << endl;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			if (cal[count]) {
				cout << setw(5) << cal[count];
				count++;
			}
			else {
				cout << setw(5) << ' ';
				count++;
			}
			
		}
		cout << endl;
	}
}

bool Month::get_leap_year()
{
	return leap_year;
}

int Month::get_days()
{
	return days;
}

int Month::get_first_day_of_week()
{
	return first_day_of_week;
}