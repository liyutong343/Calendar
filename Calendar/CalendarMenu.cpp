#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

#include "CalendarMenu.h"
#include "Month.h"

using namespace std;

bool verify_natural_number(const char* str)
{
	//判断一个字符串是否是整数，即所有位都是数字构成的
	//如果是，返回true
	//如果否，返回false

	bool is_natural_number = true;
	for (; *str != '\0'; str++) {
		switch (*str) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			break;
		default:
			return false;  // 只要有一位不是数字，就return false 注意，有了return就直接跳出这个函数了！
		}
	}
	return true;  // 否则return true
}

int force_natural_number_year()
{
	//要求输入一个不越界的自然数，即0~2147483647
	//如果输入不符合要求，会进行提示并一直要求输入，直到合法为止，此时返回该字符串对应的自然数
	//要求1：所有位均由数字组成。该条件判断由verify_narural_number实现
	//要求2：输入不越界。该条件判断由异常处理实现

	string str;
	while (true) {
		cout << "Please input year:" << endl;
		cin >> str;
		try {
			if (verify_natural_number(str.c_str()))
				return stoi(str);
			else
				cout << "Please check your input!" << endl;
		}
		catch (out_of_range) {
			cout << "Your input is out of range!" << endl;
		}
	}
}

int force_natural_number_month()
{
	//要求输入一个不越界的自然数，即0~2147483647
	//如果输入不符合要求，会进行提示并一直要求输入，直到合法为止，此时返回该字符串对应的自然数
	//要求1：所有位均由数字组成。该条件判断由verify_narural_number实现
	//要求2：输入不越界。该条件判断由异常处理实现

	string str;
	while (true) {
		cout << "Please input month:" << endl;
		cin >> str;
		try {
			if (verify_natural_number(str.c_str()))
				if (stoi(str) > 12 || stoi(str) < 1)
					cout << "Please check your input!" << endl;
				else
					return stoi(str);
			else
				cout << "Please check your input!" << endl;
		}
		catch (out_of_range) {
			cout << "Your input is out of range!" << endl;
		}
	}
}

CalendarMenu::CalendarMenu()
{

}

void CalendarMenu::show()
{
	cout << "This is a small program which could display the calendar of a certain month or a certain year~" << endl;
	cout << "Please choose the function:" << endl;
	cout << "1 display the calendar of a certain month" << endl;
	cout << "2 display the calendar of a certain year" << endl;
	cout << "0 exit" << endl;
}

void CalendarMenu::display_month()
{
	cout << endl;

	int y, m;
	
	y = force_natural_number_year();
	m = force_natural_number_month();

	Month month(y, m);

	cout << endl;
	month.show();

}

void CalendarMenu::display_year()
{
	cout << endl;

	//声明变量
	int y;
	int j_f_m[138] = { 0 }, a_m_j[138] = { 0 }, 
		j_a_s[138] = { 0 }, o_n_d[138] = { 0 };

	y = force_natural_number_year();

	//建立对象
	Month Jan(y, 1), Feb(y, 2), Mar(y, 3), Apr(y, 4),
		May(y, 5), Jun(y, 6), Jul(y, 7), Aug(y, 8),
		Sep(y, 9), Oct(y, 10), Nov(y, 11), Dec(y, 12);

	//数组赋值
	for (int i = 0;i < 138;i++) {
		if (i % 23 < 7) 
			j_f_m[i] = Jan.cal[7 * int(i / 23) + i % 23];
		else if(i % 23 > 7 && i % 23 < 15)
			j_f_m[i] = Feb.cal[7 * int(i / 23) + i % 23 - 8];
		else if(i % 23 > 15)
			j_f_m[i] = Mar.cal[7 * int(i / 23) + i % 23 - 16];
	}

	for (int i = 0;i < 138;i++) {
		if (i % 23 < 7)
			a_m_j[i] = Apr.cal[7 * int(i / 23) + i % 23];
		else if (i % 23 > 7 && i % 23 < 15)
			a_m_j[i] = May.cal[7 * int(i / 23) + i % 23 - 8];
		else if (i % 23 > 15)
			a_m_j[i] = Jun.cal[7 * int(i / 23) + i % 23 - 16];
	}

	for (int i = 0;i < 138;i++) {
		if (i % 23 < 7)
			j_a_s[i] = Jul.cal[7 * int(i / 23) + i % 23];
		else if (i % 23 > 7 && i % 23 < 15)
			j_a_s[i] = Aug.cal[7 * int(i / 23) + i % 23 - 8];
		else if (i % 23 > 15)
			j_a_s[i] = Sep.cal[7 * int(i / 23) + i % 23 - 16];
	}
	
	for (int i = 0;i < 138;i++) {
		if (i % 23 < 7)
			o_n_d[i] = Oct.cal[7 * int(i / 23) + i % 23];
		else if (i % 23 > 7 && i % 23 < 15)
			o_n_d[i] = Nov.cal[7 * int(i / 23) + i % 23 - 8];
		else if (i % 23 > 15)
			o_n_d[i] = Dec.cal[7 * int(i / 23) + i % 23 - 16];
	}

	//打印表头
	cout << endl;
	for (int i = 0; i < 23; i++)
		cout << setw(5) << "*";
	cout << endl << endl;
	cout << setw(60) << "Calendar of " << y << endl << endl;
	for (int i = 0; i < 23; i++)
		cout << setw(5) << "*";
	cout << endl << endl;

	//打印1~3月
	cout << setw(20) << "January" << setw(40) << "February" << setw(40) << "March" << endl;
	cout << setw(5) << "Son." << setw(5) << "Mon." << setw(5) << "Tue." << setw(5)
		<< "Wed." << setw(5) << "Thu." << setw(5) << "Fri." << setw(5) << "Sat." << setw(5) << ' '
		<< setw(5) << "Son." << setw(5) << "Mon." << setw(5) << "Tue." << setw(5)
		<< "Wed." << setw(5) << "Thu." << setw(5) << "Fri." << setw(5) << "Sat." << setw(5) << ' '
		<< setw(5) << "Son." << setw(5) << "Mon." << setw(5) << "Tue." << setw(5)
		<< "Wed." << setw(5) << "Thu." << setw(5) << "Fri." << setw(5) << "Sat." << endl;
	for (int i = 0; i < 138;i++) {
		if (j_f_m[i])
			cout << setw(5) << j_f_m[i];
		else
			cout << setw(5) << ' ';
		if (i % 23 == 22)
			cout << endl;
	}

	//打印4~6月
	cout << setw(20) << "April" << setw(40) << "May" << setw(40) << "June" << endl;
	cout << setw(5) << "Son." << setw(5) << "Mon." << setw(5) << "Tue." << setw(5)
		<< "Wed." << setw(5) << "Thu." << setw(5) << "Fri." << setw(5) << "Sat." << setw(5) << ' '
		<< setw(5) << "Son." << setw(5) << "Mon." << setw(5) << "Tue." << setw(5)
		<< "Wed." << setw(5) << "Thu." << setw(5) << "Fri." << setw(5) << "Sat." << setw(5) << ' '
		<< setw(5) << "Son." << setw(5) << "Mon." << setw(5) << "Tue." << setw(5)
		<< "Wed." << setw(5) << "Thu." << setw(5) << "Fri." << setw(5) << "Sat." << endl;
	for (int i = 0; i < 138;i++) {
		if(a_m_j[i])
			cout << setw(5) << a_m_j[i];
		else
			cout << setw(5) << ' ';
		if (i % 23 == 22)
			cout << endl;
	}

	//打印7~9月
	cout << setw(20) << "July" << setw(40) << "August" << setw(40) << "September" << endl;
	cout << setw(5) << "Son." << setw(5) << "Mon." << setw(5) << "Tue." << setw(5)
		<< "Wed." << setw(5) << "Thu." << setw(5) << "Fri." << setw(5) << "Sat." << setw(5) << ' '
		<< setw(5) << "Son." << setw(5) << "Mon." << setw(5) << "Tue." << setw(5)
		<< "Wed." << setw(5) << "Thu." << setw(5) << "Fri." << setw(5) << "Sat." << setw(5) << ' '
		<< setw(5) << "Son." << setw(5) << "Mon." << setw(5) << "Tue." << setw(5)
		<< "Wed." << setw(5) << "Thu." << setw(5) << "Fri." << setw(5) << "Sat." << endl;
	for (int i = 0; i < 138;i++) {
		if(j_a_s[i])
			cout << setw(5) << j_a_s[i];
		else
			cout << setw(5) << ' ';
		if (i % 23 == 22)
			cout << endl;
	}

	//打印10~12月
	cout << setw(20) << "October" << setw(40) << "November" << setw(40) << "December" << endl;
	cout << setw(5) << "Son." << setw(5) << "Mon." << setw(5) << "Tue." << setw(5)
		<< "Wed." << setw(5) << "Thu." << setw(5) << "Fri." << setw(5) << "Sat." << setw(5) << ' '
		<< setw(5) << "Son." << setw(5) << "Mon." << setw(5) << "Tue." << setw(5)
		<< "Wed." << setw(5) << "Thu." << setw(5) << "Fri." << setw(5) << "Sat." << setw(5) << ' '
		<< setw(5) << "Son." << setw(5) << "Mon." << setw(5) << "Tue." << setw(5)
		<< "Wed." << setw(5) << "Thu." << setw(5) << "Fri." << setw(5) << "Sat." << endl;
	for (int i = 0; i < 138;i++) {
		if(o_n_d[i])
			cout << setw(5) << o_n_d[i];
		else
			cout << setw(5) << ' ';
		if (i % 23 == 22)
			cout << endl;
	}

}

void CalendarMenu::exit_system()
{
	cout << endl;
	cout << "Thanks for your support!" << endl;
	cout << "Byebye~!" << endl;
	exit(0);
}