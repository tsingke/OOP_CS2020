/*************************************************
** 功能 : 动态内存分配问题  
** 作者 : tsingke
** 创建 : 2020-10-27 
** 版权 : tsingke@sdnu.edu.cn
/**************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

/*----------------------------------*
              子函数
*-----------------------------------*/
void Fibonacci(double * p, int N)
{
	for (int i = 2; i < N; i++)
	{
		p[i] = p[i - 1] + p[i - 2];
	}
}

void show(double* p, int N)
{
	for (int i = 0; i < N; i++)
	{
		if (i%5 ==0)
		{
			cout << endl;

		}
		cout << p[i] << " ";

	}
	cout << endl;

}


/*----------------------------------*
		     主函数
*-----------------------------------*/

int main()
{

	//1.输入数组大小
	int N = 0;
	
	cout << "******斐波那契数列存储问题******" <<endl<<endl;

	cout << "请输入输出序列的长度 N = ";

	cin >> N;

	//2. 创建动态数组

	double *parray = new double[N];

	parray[0] = 0; 
	parray[1] = 1;


	//3. 计算序列数值,并存储
	Fibonacci(parray, N);


	//4. 输出序列数据
	show(parray, N);


	//5. 释放动态内存(不要忘记!)

	delete[] parray;


	system("pause");
	
	return 0;
}
