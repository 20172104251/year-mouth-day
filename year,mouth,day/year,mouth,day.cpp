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
};
void Year::setvalue(int a, int b, int c)
{
	int i,j;
	int r[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int p[12]=  { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (j = 1; j <= month; j++)
	{
		b += r[j - 1];
	}
	year = a + b / 12;
	if (year % 400 == 0 && year % 100 == 0 || year % 4 == 0)
	{
		month = b + c /
	}
	
}
int main()
{
    return 0;
}

