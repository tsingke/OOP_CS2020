/*************************************************
** ���� : ����ַ����� 
** ���� : tsingke
/**************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>

#include "Mystring.h"

using namespace std;


/*----------------------------------*
		  Main Function
*-----------------------------------*/

int main()
{

	

	Mystring str1("abcdefghi");

	Mystring str2("123456789");


	//1.����ַ�������
	cout << "---------1.����ַ�������---------" << endl;
	cout << "str1:"; str1.show();
	cout << "str2:"; str2.show();

	cout << "---------2.����ַ�������---------" << endl;
	cout << "length(str1)=" << str1.stringLength() << endl;
	cout << "length(str2)=" << str2.stringLength() << endl;

	cout << "---------3.����ַ����Ƚ�---------" << endl;
	cout<< "�ַ���1��2�ȽϽ��Ϊ:" << str1.stringCmp(str2) << endl;


	cout << "---------4.�ַ�����������---------" << endl;
	cout << "�ַ���1���ӽ��:" << str1.stringCat(str2).getPS() << endl;;

	cout << "---------5.�ַ������ݷ�ת---------" << endl;
	str1.stringReverse().show();
	str2.stringReverse().show();

	cout << "---------6.�ַ����������(��)---------" << endl;
	cout << "�ַ���1�����ַ���2:";
	str1.stringInsert(str2, 3).show();

	cout << "---------7.�ַ�������ɾ��(ɾ)---------" << endl;
	str1.stringDelete(12).show();

	cout << "---------8.�ַ��������޸�(��)---------" << endl;
	str1.stringModify(6).show();

	cout << "---------9.�ַ��������޸�(��)---------" << endl;

	str1.stringSearch();




	
	system("pause");
	
	return 0;
}


