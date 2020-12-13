#define _CRT_SECURE_NO_WARNINGS
#include "Mystring.h"
#include <iostream>
#include <cstring>
using namespace std;

//----------------------����һ��----------------------------
//���캯��
Mystring::Mystring()
{
}

//�вι��캯��
Mystring::Mystring(const char * pt)
{
	if (pt)
	{
		this->ps = new char[strlen(pt) + 1];

		strcpy(this->ps, pt);

	}
}

//�������캯��
Mystring::Mystring(const Mystring & r)
{
	if (r.ps)
	{
		this->ps = new char[strlen(r.ps) + 1];

		strcpy(this->ps, r.ps);
	}
}

//��������
Mystring::~Mystring()
{
	if (this->ps)
	{
		delete[] ps;
	}
}
//----------------------��ͨ����----------------------------
//�ַ����������Ӻ���
Mystring& Mystring::stringCat(const Mystring &r)
{

	char *pnew=NULL;


	//1. �ռ俪��
	if (r.ps)
	{
		pnew = new char[strlen(ps) + strlen(r.ps) + 1];
	}
	

	char* ptemp = pnew;

	//2. ��ʼ������ǰȫ���ַ�����������
	strcpy(ptemp, this->ps);


	//3. ��ʼ�����ⲿ�ַ���
	strcpy(ptemp+strlen(ps), r.ps);

	delete[] ps;
	//ptemp[size - 1] = '\0';//�ϲ������һ��λ�����\0

	this->ps = pnew;//�����ɵ�ǰ�������ָ�������Ƭ�ѿռ�

	return (*this);

}


//�ַ����ȽϺ���
int Mystring::stringCmp(const Mystring &r)
{
	if (r.ps)
	{
		return strcmp(this->ps, r.ps);
	}
	else
		return 1;
}

//�ַ������뺯��(��΢����)
Mystring& Mystring::stringInsert(const Mystring &r, int pos)
{
	char *pnew = NULL;

	if (r.ps)
	{
		int len1 = strlen(this->ps);
		int len2 = strlen(r.ps);

		//1. �ռ俪��
		pnew = new char[len1+len2+1];

		char *ptemp = pnew;

		//2. ��ʼ������ǰ�ַ�����ǰpos����
		int counts = 0;
		while (counts < pos)
		{
			ptemp[counts] = this->ps[counts];
			counts++;
		}

		//3. ��ʼ���������ⲿ�ַ�������
		for (int i = pos; i < pos + strlen(r.ps); i++)
		{
			ptemp[i] = r.ps[i - pos];
		}

		counts = pos + strlen(r.ps);//֮ǰ������

		//4. �������뵱ǰ�ַ��ĺ�벿��
		while (counts < len1+len2)
		{
			ptemp[counts++] = this->ps[pos++];
		}

		ptemp[len1 + len2] = '\0';//�ϲ������һ��λ�����\0

		delete[] this->ps;

		this->ps = pnew;//�����ɵ�ǰ�������ָ�������Ƭ�ѿռ�

		return (*this);
	}
}


//�ַ���ɾ������(ɾ��ĳλ��֮�������)
Mystring& Mystring::stringDelete(int pos)
{
	if (this->ps)
	{
		if (pos > strlen(ps) || pos < 0)
		{
			cout << "��������" << endl;
			getchar();
			
		}

		this->ps[pos] = '\0';
	}
	else
	{
		cout << "�ַ���Ϊ�մ�,�޷�ɾ��" << endl;
		getchar();
	
	}

	return (*this);
}


//�ַ��������޸�
Mystring& Mystring::stringModify(int pos)
{
	if (this->ps)
	{
		cout << "������" << pos << "��λ�õ��ַ�Ϊ: ";
		cin >> this->ps[pos - 1];
	}
	else
	{
		cout << "�ַ���Ϊ�մ�,�޷�ɾ��" << endl;
		getchar();
	
	}
	return *this;
}

//�ַ������ݲ���
int Mystring::stringSearch()
{
	int id=0;
	char ch;
	cout << "��������Ҫ���ҵ��ַ�: ";
	cin >> ch;

	while (ps[id]!=ch && ps[id] !='\0')
	{
		id++;
	}

	if (ps[id] == ch)
	{
		cout << "��ϲ,�ҵ��ַ�'"<<ch<<"'(��ߵ�" << id+1 << "��)" << endl;
		return id;
	}
	else
	{
		cout << "��Ǹ,δ���������ַ�'" << ch << "'" << endl;
		return -1;

	}


	
}

//�ַ�����ת
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

//�����ַ�����С
int Mystring::stringLength()
{ 
	return strlen(this->ps);
}

//����ַ�����
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
