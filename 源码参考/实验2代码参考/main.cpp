/*************************************************
** ���� : ��������  
** ���� : tsingke 
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


// ����Ǳ������һ��
int isWhichDay(int &year, int &month, int &day)
{
	int sum = 0;
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//2�·�Ԥ������Ϊ28��

	//1.�ۼƵ�ǰ�·�֮ǰ����������
	for (int i = 1; i < month; i++)
	{
		sum += days[i];
	}

	//2.���ӱ��·ݵ�������2��֮ǰ��2��֮��
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


// ����Ǳ������һ�ܣ�7��Ϊһ��
int isWhichWeek(int &year, int &month, int &day)
{
	int w = isWhichDay(year, month, day) / 7; //�����������������
	int d = isWhichDay(year, month, day) % 7; //�����������ɢ����

	if (d == 0)      //������
	{
		return w;
	}
	else           //��������
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


	// 1.������������

	cout << "������������(�ո�ָ�)" << endl;

	cin >> year >> month >> day;
	
	if (isLeapYear(year,month,day)==1)
	{
		cout << "����������!" << endl;
	}

	//2.����ǽ������һ��
	whichday = isWhichDay(year, month, day);

	cout << year << "��-" << month << "��-" << day << "��,�ǽ���ĵ� " << whichday <<"��"<< endl;


	//3.����ǽ���ĵڼ���
	whichweek = isWhichWeek(year, month, day);

	cout << year << "��-" << month << "��-" << day << "��,�ǽ���ĵ� " << whichweek << "��" << endl;





	system("pause");
	
	return 0;
}