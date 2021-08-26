#pragma once
class Month{
public:
	Month();
	Month(int y, int m);
	bool set_leap_year(int y);			//判断闰年
	int set_days(bool ly, int m);		//判断天数
	int set_first_day_of_week(int y, int m);
	void show();						//显示函数
	bool get_leap_year();				//得知闰年
	int get_days();						//得知天数
	int get_first_day_of_week();		//得知1号是星期几
	int cal[42] = { 0 };

private:
	int year;							//年份
	int month;							//月份
	bool leap_year;						//闰年
	int days;							//天数
	int first_day_of_week;				//1号是星期几
};