/*************************************************
** 功能 : ACM-木棍最大周长问题
** 作者 : tsingke
** 创建 : 2020-10-19 / 08:38
** 版权 : tsingke@sdnu.edu.cn
/**************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <windows.h>

using namespace std;


double maxArea = 0.0;
double maxPerimeter = 0.0;


double area_a = 0.0;
double area_b = 0.0;
double area_c = 0.0;


double perim_a = 0.0;
double perim_b = 0.0;
double perim_c = 0.0;



/*----------------------------------*
	 三角形相关信息
*-----------------------------------*/

//计算是否构成三角形
int isTriangle(const double &r1,const double &r2, const double&r3)
{
	if ((r1 + r2 > r3) && (r1 + r3 > r2) && (r2 + r3 > r1))
	{
		return 1;
	}
	else
		return 0;
}

//计算三角形周长
double perimeter(const double &r1, const double &r2, const double&r3)
{
	return (r1 + r2 + r3);
}



//计算三角形面积
double area(const double &r1, const double &r2, const double&r3)
{

	double p = 0.5*(r1 + r2 + r3);


	return sqrt(p*(p - r1)*(p - r2)*(p - r3));


}




/*----------------------------------*
  三角形构建算法:第一种,复杂度o(n^3))
*-----------------------------------*/
int searchMaxLength(const double *plen, const int num)
{
	bool canConstructTriangle = false;

	for (int i = 0; i < num; i++)
	{
		for (int j = i+1; j < num; j++)
		{
			for (int k = j+1; k < num; k++)
			{

				if (isTriangle(plen[i], plen[j], plen[k]))
				{
					double tempPerimeter = perimeter(plen[i], plen[j], plen[k]);

					if (tempPerimeter > maxPerimeter)
					{
						maxPerimeter = tempPerimeter;

						//记录当前边长
						perim_a = plen[i];
						perim_b = plen[j];
						perim_c = plen[k];

					}

					canConstructTriangle = true;//存在构成三角形的木棍

				}

				else
					continue;
			}

		}
	}

	if (canConstructTriangle == false)
	{
		cout << "提示: 当前木棍长度无法构成任何三角形!" << endl;
		return 0;
	}
	else
		return 1;


}

int searchMaxArea(const double *plen, const int num)
{
	bool canConstructTriangle = 0;

	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			for (int k = j + 1; k < num; k++)
			{

				if (isTriangle(plen[i], plen[j], plen[k]))
				{
					double tempArea = area(plen[i], plen[j], plen[k]);
					

					if (tempArea > maxArea)
					{
						maxArea = tempArea;

						//记录当前边长
						area_a = plen[i];
						area_b = plen[j];
						area_c = plen[k];

					}

					canConstructTriangle = 1;//存在构成三角形的木棍

				}

				else
					continue;
			}
		}
	}

	if (canConstructTriangle == 0)
	{
		cout << "提示: 当前木棍长度无法构成任何三角形!" << endl;
		return 0;

	}
	else
		return 1;


}

/*----------------------------------*
  三角形构建算法:第二种,复杂度o(n^log(n)))
*-----------------------------------*/

int cmpfunc(const void* a, const void* b)
{
	if (*(double*)b - *(double*)a > 0)
	{
		return 1;
	}
	else if (*(double*)b - *(double*)a < 0)
	{
		return -1;
	}

	else
		return 0;
	
}

int searchMaxLength_log(double *plen, const int num)
{

	//1. 按照木棍长度从大到小排序
	qsort(plen, num, sizeof(plen[0]), cmpfunc);


	//2. 构建三角形,输出最大周长
	bool canConstructTriangle = 0;

	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			for (int k = j + 1; k < num; k++)
			{

				if (isTriangle(plen[i], plen[j], plen[k]))
				{
					double tempPerimeter = perimeter(plen[i], plen[j], plen[k]);

					if (tempPerimeter > maxPerimeter)
					{
						maxPerimeter = tempPerimeter;

						//记录当前边长
						perim_a = plen[i];
						perim_b = plen[j];
						perim_c = plen[k];

					}

					canConstructTriangle = 1;//存在构成三角形的木棍

					break;//找到后就终止搜索,不再往下搜索

				}

				else
					continue;
			}
		}
	}

	if (canConstructTriangle == 0)
	{
		
		return 0;

	}
	else
		return 1;

}



/*----------------------------------*
	      主函数
*-----------------------------------*/

int main()
{


	/*----------------------------------*
		   1. 输入木棍个数和长度
	*-----------------------------------*/
	cout << "-------------- 输入数据 --------------" << endl;

	cout << "请输入木棍的总个数 m = ";

	int m;
	cin >> m;

	// 动态分配内存空间，存储木棍长度

	double *len = new double[m];

	cout << "请依次输入" << m << "根木棍的长度"<<endl;

	for (int i = 0; i < m; i++)
	{
		cout << "len[" << i << "] = ";
		cin >> len[i];


	}
	

	cout <<endl<<"-------------- 输出结果 --------------" << endl;


	/*----------------------------------*
	      2. 搜索最大周长,并输出周长
	*-----------------------------------*/


	//int success = searchMaxLength(len, m); //复杂度高
	int length_success = searchMaxLength_log(len, m);//复杂度低

	if (length_success == 1)
	{
		cout << "最大周长: " << maxPerimeter << " (边长为: " << perim_a << "," << perim_b << "," << perim_c << ")" << endl;

	}
	else
	{
		cout << 0 << endl;
		cout << "提示: 当前木棍长度无法构成任何三角形!" << endl;
	}
	

	/*----------------------------------*
		  3. 搜索最大面积,并输出面积
	*-----------------------------------*/

	int area_success = searchMaxArea(len, m);

	if (area_success == 1)
	{
		cout << "最大面积: " << maxArea << " (边长为: " << area_a << "," << area_b << "," << area_c << ")" << endl << endl;

	}
	else
	{
		cout << 0 << endl;
		cout << "提示: 当前木棍长度无法构成任何三角形!"<<endl;
	}



	/*----------------------------------*
	       4.释放动态内存空间
	*-----------------------------------*/


	delete[] len;


	system("pause");

	return 0;
}
