/*************************************************
** 功能 : 日期问题  
** 作者 : tsingke 
/**************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;


int isLeapYear(int &year, int &month,int &day)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{

		return 1;
	}
	else
	{
		return 0;
	}
}


// 输出是本年的哪一天
int isWhichDay(int &year, int &month, int &day)
{
	int sum = 0;
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//2月份预先设置为28天

	//1.累计当前月份之前的所有天数
	for (int i = 1; i < month; i++)
	{
		sum += days[i];
	}

	//2.补加本月份的天数（2月之前，2月之后）
	if (isLeapYear(year,month,day))
	{
		if (month <= 2)//2020-1-31
		{
			return sum + day;
		}
		else
		{
			return sum + day + 1;
		}
	}
	else
	{
		return sum + day;
	}
}


// 输出是本年的哪一周，7天为一周
int isWhichWeek(int &year, int &month, int &day)
{
	int w = isWhichDay(year, month, day) / 7; //计算包含的整数周数
	int d = isWhichDay(year, month, day) % 7; //计算包含的零散天数

	if (d == 0)      //整数周
	{
		return w;
	}
	else           //非整数周
	{
		return w + 1;
	}

}


/*----------------------------------*
		  Main Function
*-----------------------------------*/

int main()
{

	int year, month, day;

	int whichday = 0;
	int whichweek = 0;


	// 1.输入日期数据

	cout << "请输入年月日(空格分割)" << endl;

	cin >> year >> month >> day;
	
	if (isLeapYear(year,month,day)==1)
	{
		cout << "今年是闰年!" << endl;
	}

	//2.输出是今年的哪一天
	whichday = isWhichDay(year, month, day);

	cout << year << "年-" << month << "月-" << day << "日,是今年的第 " << whichday <<"天"<< endl;


	//3.输出是今年的第几周
	whichweek = isWhichWeek(year, month, day);

	cout << year << "年-" << month << "月-" << day << "日,是今年的第 " << whichweek << "周" << endl;





	system("pause");
	
	return 0;
}