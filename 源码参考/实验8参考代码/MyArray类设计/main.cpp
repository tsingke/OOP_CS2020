/*************************************************
** ���� : ���������
** ���� : tsingke
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
	//1. �������������������
	MyArray array1(10);
	MyArray array2(30);
	MyArray array3(20);
	MyArray array4;


	//2.������������������
	cout << "array1 = "; array1.show();
	cout << "array2 = "; array2.show();
	cout << "array3 = "; array3.show();

	//3. �������������ʵ�ֶ���Ӽ���
	array3 = array1 + array2;
	array4 = array1 - array2;

	cout << "array1 + array2 = "; array3.show();
	cout << "array1 - array2 = "; array4.show();

	//4.������ͨ��Ա�����޸Ķ����ڵ�����
	array1.modifyArray();

	cout << "�޸ĺ������:"; 
	array1.show();

	system("pause");
	
	return 0;
}