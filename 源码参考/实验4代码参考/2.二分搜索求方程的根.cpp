/*************************************************
** 功能 : 采用二分法求任意函数f(x)的一个零点
** 作者 : tsingke
** 创建 : 2020-10-27
** 版权 : tsingke@sdnu.edu.cn
/**************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std;

const double eps = 1e-6;



/*----------------------------------*
*             定义子函数
*-----------------------------------*/

//功能: 定义任意的某个函数f(x)
double function(double x)
{
	double temp = 1.56*pow(x - 1, 6) - 3.128*pow(x - 2, 4) + 2.85 * pow(x, 4) + 15 * pow(x, 3) - 2.645 * pow(x, 2) + 274 * x - 24;

	return temp;

}


//功能: 采用二分法寻找任意函数的一个零点(实根)
double binarySearch(double &left, double &right)
{
	int count = 0;

	double middle = 0.5*(left + right);



	while (fabs(function(middle)) > eps)
	{
		cout << "开始第" << ++count << "次搜索..." << endl;

		if (function(left)*function(middle) < 0)
		{
			right = middle;
		}
		else
		{
			left = middle;
		}

		middle = 0.5*(left + right);

	}

	return middle;
}

/*----------------------------------*
*               主函数
*-----------------------------------*/

int main()
{
	cout << "******二分法求解函数的零点坐标数值******" << endl;

	double xmin, xmax;
	double randx1, randx2;


	// 1. 输入函数自变量搜索范围
	cout << "请输入搜索左边界xmin = "; cin >> xmin;
	cout << "请输入搜索右边界xmax = "; cin >> xmax;



	//2. 在搜索范围内寻找两个随机点,使得他们的函数值符号不同
	srand(int(time(NULL))); //产生随机数种子
	do
	{
		randx1 = xmin + rand() / (RAND_MAX + 1.0)*(xmax - xmin);
		randx2 = xmin + rand() / (RAND_MAX + 1.0)*(xmax - xmin);

	} while (function(randx1)*function(randx2) > 0);
	

	//3.在区间[randx1,randx2]范围内采用二分法搜索给定方程的一个根(零点)
	double root = binarySearch(randx1, randx2);



	//4. 输出函数的零点
	cout << "恭喜,已搜索到函数f(x)=0的1个根, x = " << setprecision(10)<<root << endl;




	system("pause");

	return 0;
}