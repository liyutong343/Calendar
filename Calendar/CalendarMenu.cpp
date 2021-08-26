#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

#include "CalendarMenu.h"
#include "Month.h"

using namespace std;

bool verify_natural_number(const char* str)
{
	//�ж�һ���ַ����Ƿ���������������λ�������ֹ��ɵ�
	//����ǣ�����true
	//����񣬷���false

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
			return false;  // ֻҪ��һλ�������֣���return false ע�⣬����return��ֱ��������������ˣ�
		}
	}
	return true;  // ����return true
}

int force_natural_number_year()
{
	//Ҫ������һ����Խ�����Ȼ������0~2147483647
	//������벻����Ҫ�󣬻������ʾ��һֱҪ�����룬ֱ���Ϸ�Ϊֹ����ʱ���ظ��ַ�����Ӧ����Ȼ��
	//Ҫ��1������λ����������ɡ��������ж���verify_narural_numberʵ��
	//Ҫ��2�����벻Խ�硣�������ж����쳣����ʵ��

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
	//Ҫ������һ����Խ�����Ȼ������0~2147483647
	//������벻����Ҫ�󣬻������ʾ��һֱҪ�����룬ֱ���Ϸ�Ϊֹ����ʱ���ظ��ַ�����Ӧ����Ȼ��
	//Ҫ��1������λ����������ɡ��������ж���verify_narural_numberʵ��
	//Ҫ��2�����벻Խ�硣�������ж����쳣����ʵ��

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

	//��������
	int y;
	int j_f_m[138] = { 0 }, a_m_j[138] = { 0 }, 
		j_a_s[138] = { 0 }, o_n_d[138] = { 0 };

	y = force_natural_number_year();

	//��������
	Month Jan(y, 1), Feb(y, 2), Mar(y, 3), Apr(y, 4),
		May(y, 5), Jun(y, 6), Jul(y, 7), Aug(y, 8),
		Sep(y, 9), Oct(y, 10), Nov(y, 11), Dec(y, 12);

	//���鸳ֵ
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

	//��ӡ��ͷ
	cout << endl;
	for (int i = 0; i < 23; i++)
		cout << setw(5) << "*";
	cout << endl << endl;
	cout << setw(60) << "Calendar of " << y << endl << endl;
	for (int i = 0; i < 23; i++)
		cout << setw(5) << "*";
	cout << endl << endl;

	//��ӡ1~3��
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

	//��ӡ4~6��
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

	//��ӡ7~9��
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

	//��ӡ10~12��
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