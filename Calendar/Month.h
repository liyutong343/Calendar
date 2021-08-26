#pragma once
class Month{
public:
	Month();
	Month(int y, int m);
	bool set_leap_year(int y);			//�ж�����
	int set_days(bool ly, int m);		//�ж�����
	int set_first_day_of_week(int y, int m);
	void show();						//��ʾ����
	bool get_leap_year();				//��֪����
	int get_days();						//��֪����
	int get_first_day_of_week();		//��֪1�������ڼ�
	int cal[42] = { 0 };

private:
	int year;							//���
	int month;							//�·�
	bool leap_year;						//����
	int days;							//����
	int first_day_of_week;				//1�������ڼ�
};