#define _CRT_SECURE_NO_WARNINGS
#include "Mystring.h"
#include <iostream>
#include <cstring>
using namespace std;

//----------------------三构一析----------------------------
//构造函数
Mystring::Mystring()
{
}

//有参构造函数
Mystring::Mystring(const char * pt)
{
	if (pt)
	{
		this->ps = new char[strlen(pt) + 1];

		strcpy(this->ps, pt);

	}
}

//拷贝构造函数
Mystring::Mystring(const Mystring & r)
{
	if (r.ps)
	{
		this->ps = new char[strlen(r.ps) + 1];

		strcpy(this->ps, r.ps);
	}
}

//析构函数
Mystring::~Mystring()
{
	if (this->ps)
	{
		delete[] ps;
	}
}
//----------------------普通函数----------------------------
//字符串对象连接函数
Mystring& Mystring::stringCat(const Mystring &r)
{

	char *pnew=NULL;


	//1. 空间开辟
	if (r.ps)
	{
		pnew = new char[strlen(ps) + strlen(r.ps) + 1];
	}
	

	char* ptemp = pnew;

	//2. 开始拷贝当前全部字符串对象数据
	strcpy(ptemp, this->ps);


	//3. 开始拷贝外部字符串
	strcpy(ptemp+strlen(ps), r.ps);

	delete[] ps;
	//ptemp[size - 1] = '\0';//合并后最后一个位置填充\0

	this->ps = pnew;//继续由当前对象里的指针管理这片堆空间

	return (*this);

}


//字符串比较函数
int Mystring::stringCmp(const Mystring &r)
{
	if (r.ps)
	{
		return strcmp(this->ps, r.ps);
	}
	else
		return 1;
}

//字符串插入函数(稍微复杂)
Mystring& Mystring::stringInsert(const Mystring &r, int pos)
{
	char *pnew = NULL;

	if (r.ps)
	{
		int len1 = strlen(this->ps);
		int len2 = strlen(r.ps);

		//1. 空间开辟
		pnew = new char[len1+len2+1];

		char *ptemp = pnew;

		//2. 开始拷贝当前字符串的前pos部分
		int counts = 0;
		while (counts < pos)
		{
			ptemp[counts] = this->ps[counts];
			counts++;
		}

		//3. 开始完整插入外部字符串对象
		for (int i = pos; i < pos + strlen(r.ps); i++)
		{
			ptemp[i] = r.ps[i - pos];
		}

		counts = pos + strlen(r.ps);//之前的数据

		//4. 继续插入当前字符的后半部分
		while (counts < len1+len2)
		{
			ptemp[counts++] = this->ps[pos++];
		}

		ptemp[len1 + len2] = '\0';//合并后最后一个位置填充\0

		delete[] this->ps;

		this->ps = pnew;//继续由当前对象里的指针管理这片堆空间

		return (*this);
	}
}


//字符串删除函数(删除某位置之后的数据)
Mystring& Mystring::stringDelete(int pos)
{
	if (this->ps)
	{
		if (pos > strlen(ps) || pos < 0)
		{
			cout << "输入有误" << endl;
			getchar();
			
		}

		this->ps[pos] = '\0';
	}
	else
	{
		cout << "字符串为空串,无法删除" << endl;
		getchar();
	
	}

	return (*this);
}


//字符串内容修改
Mystring& Mystring::stringModify(int pos)
{
	if (this->ps)
	{
		cout << "更换第" << pos << "个位置的字符为: ";
		cin >> this->ps[pos - 1];
	}
	else
	{
		cout << "字符串为空串,无法删除" << endl;
		getchar();
	
	}
	return *this;
}

//字符串内容查找
int Mystring::stringSearch()
{
	int id=0;
	char ch;
	cout << "请输入你要查找的字符: ";
	cin >> ch;

	while (ps[id]!=ch && ps[id] !='\0')
	{
		id++;
	}

	if (ps[id] == ch)
	{
		cout << "恭喜,找到字符'"<<ch<<"'(左边第" << id+1 << "个)" << endl;
		return id;
	}
	else
	{
		cout << "抱歉,未搜索到该字符'" << ch << "'" << endl;
		return -1;

	}


	
}

//字符串翻转
Mystring& Mystring::stringReverse()
{
	char temp;

	int size = stringLength();

	for (int i = 0,j = size -1; i <j ; i++,j--)
	{
		temp = ps[i];
		ps[i] = ps[j];
		ps[j] = temp;
	}

	return *this;

}

//计算字符串大小
int Mystring::stringLength()
{ 
	return strlen(this->ps);
}

//输出字符对象
Mystring& Mystring::show()
{

	cout << this->ps;
	cout << endl;

	return (*this);

}

char * Mystring::getPS()
{
	return ps;
}
