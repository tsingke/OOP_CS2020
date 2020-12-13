#include "Arrays.h"
#include <iostream>
#include<cstdlib>
using namespace std;

//---------------------三构一析----------------

//有参构造函数(带默认形参数值)
MyArray::MyArray(int _size)
{
	cout << "+普通构造函数+" << endl;

	this->size = _size;

	this->ps = new int[_size];

	//初始化为[0,10]内的随机整数
	for (int i = 0; i < _size; i++)
	{
		this->ps[i] = rand() % 11;

	}


}

//拷贝构造函数(老对象初始化当前新对象)
MyArray::MyArray(const MyArray & r)
{
	cout << "+拷贝构造函数+" << endl;

	if (r.ps)
	{
		//为新对象分配空间
		this->ps = new int[r.size];


		//老对象数据初始化新对象
		this->size = r.size;

		for (int i = 0; i < this->size; i++)
		{
			this->ps[i] = r.ps[i];
		}

	}
	else
	{
		cout << "右值对象为空,无法进行赋值" << endl;
	}


}
//析构函数
MyArray::~MyArray()
{
	if (this->ps)
	{
		delete[] this->ps;
	}

	cout << "~析构函数" << endl;
}
//---------------------普通函数----------------

void MyArray::show()
{
	if (this->ps)
	{
		for (int i = 0; i < this->size; i++)
		{
			cout << this->ps[i] << " ";
		}

		cout << endl;
	}


}

MyArray & MyArray::modifyArray()
{
	if (ps)
	{
		cout << "请输入您要修改的元素标号:";
		int id; cin >> id;

		if (id >= 0 && id < size)
		{
			cout << "修改元素数值: ps[" << id << "] = ";
			cin >> ps[id];
		}
		else
			cout << "您输入的元素标号超出数组范围!" << endl;
	}
	else
	{
		cout << "数组无内存空间,无法修改元素!" << endl;
	}
	return *this;

}

//重载赋值=运算符:成员函数形式:二目运算符(老对象 = 老对象)
MyArray& MyArray::operator=( const MyArray & r)
{
	cout << "  =赋值运算符= " << endl;

	//1. 清空当前老对象的内存空间,重新分配新空间
	if (this->ps) { delete[] ps; }

	if (r.ps)
	{
		this->ps = new int[r.size];

	}

	//2. 数据对位赋值拷贝(批量对位赋值)
	this->size = r.size;

	for (int i = 0; i < this->size; i++)
	{
		this->ps[i] = r.ps[i];
	}

	return (*this);

}

//重载加法+运算符(成员函数形式):二目运算符,可以少提供一个操作数,第一操作数由*this对象担当
MyArray MyArray::operator+( const MyArray &r)
{
	cout << "  +加法运算符+ " << endl;

	//执行加法操作的两个数组对象大小不一定相同,所以以小数组尺寸加法为准
	int minsize = (this->size <= r.size) ? this->size : r.size;
	

	//1.创建临时数组类对象temp
	MyArray temp(minsize);

	//2.批量加法操作
	for (int i = 0; i < minsize; i++)
	{
		temp.ps[i] = this->ps[i] + r.ps[i];
	}

	//3.返回对象类型(不要返回对象引用,因为temp对象很快会被释放)
	return temp;

}


//重载减法运算符(友元函数形式):二目运算符,几目运算符友元函数需要提供几个操作数
MyArray operator-(MyArray & r1, MyArray & r2)
{

	cout << "  -减法运算符- " << endl;

	//执行加法操作的两个数组对象大小不一定相同,所以以小数组加法为准
	int minsize = r1.size <= r2.size ? r1.size : r2.size;

	//1.创建临时数组类对象temp
	MyArray temp(minsize);

	//2.批量减法操作
	for (int i = 0; i < minsize; i++)
	{
		temp.ps[i] = r1.ps[i] - r2.ps[i];
	}

	//3.返回对象类型(不要返回对象引用,因为temp对象很快会被释放)
	return temp;
}
