/*************************************************
** 功能 : 数组类设计
** 作者 : tsingke
/**************************************************/

#include <iostream>
#include <cstdlib>
#include "Arrays.h"

using namespace std;

/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
	//1. 生成数组类的三个对象
	MyArray array1(10);
	MyArray array2(30);
	MyArray array3(20);
	MyArray array4;


	//2.输出数组类的三个对象
	cout << "array1 = "; array1.show();
	cout << "array2 = "; array2.show();
	cout << "array3 = "; array3.show();

	//3. 调用运算符函数实现对象加减法
	array3 = array1 + array2;
	array4 = array1 - array2;

	cout << "array1 + array2 = "; array3.show();
	cout << "array1 - array2 = "; array4.show();

	//4.调用普通成员函数修改对象内的数据
	array1.modifyArray();

	cout << "修改后的数组:"; 
	array1.show();

	system("pause");
	
	return 0;
}