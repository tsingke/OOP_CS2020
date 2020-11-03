
/*************************************************
** 功能 : 设计栈类(先入后出)
** 作者 : tsingke
** 创建 : 2020-11-3
** 版权 : tsingke@sdnu.edu.cn
/**************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <windows.h>

using namespace std;

const int MAXSIZE = 20;

/*----------------------------------*
	  栈类定义
*-----------------------------------*/
class Stack
{

private:

	int top;         //栈顶访问指示器

	double data[MAXSIZE];//存储栈数据

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
	     类成员函数定义
*-----------------------------------*/

//构造函数
Stack::Stack()
{
	top = 0;
	memset(data, 0, sizeof(data));//统一初始化为0
}

//析构函数
Stack::~Stack()
{
	
}

//普通初始化函数
void Stack::initial()
{
	top = 0;
	memset(data, 0, sizeof(data));//统一初始化为0

}

//判断栈是否为满
bool Stack::isFull()
{
	if (top == MAXSIZE)

		return true;

	else
		return false;
}

//判断栈是否为空
bool Stack::isEmpty()
{
	if (top == 0)

		return true;

	else
		return false;
}

//入栈操作
void Stack::push(double& val)
{
	data[top] = val;
	top++;//先入元素,后上移指示器

}

//出栈操作
double Stack::pop()
{
	top--;//下移指示器到元素

	return data[top];//输出元素

}

//计算栈大小
int Stack::sizeStack()
{
	return top;
}

//返回栈大小
int Stack::getTop()
{
	return top;
}

/*----------------------------------*
*         Main Function
*-----------------------------------*/

int main()
{

	cout << "********栈类设计与测试********" << endl;

	//1.生成栈对象
	Stack ss;

	cout << "当前栈大小为： " << ss.sizeStack() <<", 允许继续入栈..."<<endl<<endl;


	//2.执行入栈操作
	double temp = 0;
	
	while (!ss.isFull())
	{
		cout << "压栈，请输入数据(0终止)：";

		cin >> temp;

		//提前终止循环
		if (temp == 0)
		{
			cout << "***********入栈完毕!**********" << endl << endl;
			break;
		}

		ss.push(temp);
		cout << "成功入栈!" << endl;

	}


	//3. 输出栈内元素
	cout << "从栈顶依次输出当前栈内"<<ss.getTop()<<"个数据："<<endl;

	while(!ss.isEmpty())
	{
		cout<<ss.pop()<<" ";
	}
	
	cout << endl;


	system("pause");

	return 0;
}

