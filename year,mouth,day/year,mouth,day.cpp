// year,mouth,day.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Year
{
private:
	int year;
	int month;
	int day;
public:
	Year()
	{
		year = 0;
		month = 0;
		day = 0;
	}
	void setvalue(int a, int b, int c);
	void display();
	Year operator +(Year & ol);
	Year operator -(Year & o2);
	void jiajia();
};
void Year::setvalue(int a, int b, int c)
{
	year = a;
	month = b;
	day = c;
}
Year Year::operator+(Year & o1)
{
	Year date;
	date.setvalue(year + o1.year, month + o1.month, day + o1.day);
	return date;
}
void Year::display()
{
	cout << year << "年" << month << "月" << day<<"日"<< endl;
}
void Year::jiajia()
{
	int jyear,liang,i;
	int r[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };//闰年
	int p[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//平年
	liang = month;
	jyear = liang / 12;
	month = liang % 12;
	year =year+jyear;
	cout << year << "年" << endl;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		for (i = 1; i < month; i++)
		{
			liang = r[i];
		}
		cout << "liang=="<<liang << endl;
	}
	else
	{
		for (i = 1; i < month; i++)
		{
			liang = p[i];
		}
		cout << "liang=="<<liang << endl;
	}
	if (day / liang > 0)
	{
		month = liang+day / liang;
		day = day%liang;
		if (month >= 12)
		{
			year=year+month/12;
		}
	}
}
int main()
{
	Year q1, q2, q3;
	q1.setvalue(1999, 12, 20);
	q2.setvalue(3, 12, 21);
	q3 = q1 + q2;
	q3.display();
	q3.jiajia();
	q3.display();
    return 0;
}

