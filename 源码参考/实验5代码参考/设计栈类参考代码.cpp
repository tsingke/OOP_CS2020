
/*************************************************
** ���� : ���ջ��(������)
** ���� : tsingke
** ���� : 2020-11-3
** ��Ȩ : tsingke@sdnu.edu.cn
/**************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <windows.h>

using namespace std;

const int MAXSIZE = 20;

/*----------------------------------*
			ջ�ඨ��
*-----------------------------------*/
class Stack
{

private:

	int top;         //ջ������ָ��

	double data[MAXSIZE];//�洢ջ����

public:

	Stack();
	~Stack();
	void  initial();

	bool  isFull();
	bool  isEmpty();

	void push(double& val);
	double pop();

	int sizeStack();
	int getTop();


};


/*----------------------------------*
	     ���Ա��������
*-----------------------------------*/

//���캯��
Stack::Stack()
{
	top = 0;
	memset(data, 0, sizeof(data));//ͳһ��ʼ��Ϊ0
}

//��������
Stack::~Stack()
{
	
}

//��ͨ��ʼ������
void Stack::initial()
{
	top = 0;
	memset(data, 0, sizeof(data));//ͳһ��ʼ��Ϊ0

}

//�ж�ջ�Ƿ�Ϊ��
bool Stack::isFull()
{
	if (top == MAXSIZE)

		return true;

	else
		return false;
}

//�ж�ջ�Ƿ�Ϊ��
bool Stack::isEmpty()
{
	if (top == 0)

		return true;

	else
		return false;
}

//��ջ����
void Stack::push(double& val)
{
	data[top] = val;
	top++;//����Ԫ��,������ָʾ��

}

//��ջ����
double Stack::pop()
{
	top--;//����ָʾ����Ԫ��

	return data[top];//���Ԫ��

}

//����ջ��С
int Stack::sizeStack()
{
	return top;
}

//����ջ��С
int Stack::getTop()
{
	return top;
}

/*----------------------------------*
*         Main Function
*-----------------------------------*/

int main()
{

	cout << "********ջ����������********" << endl;

	//1.����ջ����
	Stack ss;

	cout << "��ǰջ��СΪ�� " << ss.sizeStack() <<", ���������ջ..."<<endl<<endl;


	//2.ִ����ջ����
	double temp = 0;
	
	while (!ss.isFull())
	{
		cout << "ѹջ������������(0��ֹ)��";

		cin >> temp;

		//��ǰ��ֹѭ��
		if (temp == 0)
		{
			cout << "***********��ջ���!**********" << endl << endl;
			break;
		}

		ss.push(temp);
		cout << "�ɹ���ջ!" << endl;

	}


	//3. ���ջ��Ԫ��
	cout << "��ջ�����������ǰջ��"<<ss.getTop()<<"�����ݣ�"<<endl;

	while(!ss.isEmpty())
	{
		cout<<ss.pop()<<" ";
	}
	
	cout << endl;


	system("pause");

	return 0;
}

