/*************************************************
** 功能 : 设计字符串类 
** 作者 : tsingke
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


	//1.输出字符串内容
	cout << "---------1.输出字符串内容---------" << endl;
	cout << "str1:"; str1.show();
	cout << "str2:"; str2.show();

	cout << "---------2.输出字符串长度---------" << endl;
	cout << "length(str1)=" << str1.stringLength() << endl;
	cout << "length(str2)=" << str2.stringLength() << endl;

	cout << "---------3.输出字符串比较---------" << endl;
	cout<< "字符串1与2比较结果为:" << str1.stringCmp(str2) << endl;


	cout << "---------4.字符串内容连接---------" << endl;
	cout << "字符串1连接结果:" << str1.stringCat(str2).getPS() << endl;;

	cout << "---------5.字符串内容反转---------" << endl;
	str1.stringReverse().show();
	str2.stringReverse().show();

	cout << "---------6.字符串对象插入(增)---------" << endl;
	cout << "字符串1插入字符串2:";
	str1.stringInsert(str2, 3).show();

	cout << "---------7.字符串对象删除(删)---------" << endl;
	str1.stringDelete(12).show();

	cout << "---------8.字符串对象修改(改)---------" << endl;
	str1.stringModify(6).show();

	cout << "---------9.字符串对象修改(查)---------" << endl;

	str1.stringSearch();




	
	system("pause");
	
	return 0;
}


