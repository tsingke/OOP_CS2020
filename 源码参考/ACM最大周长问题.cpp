/*************************************************
** ���� : ACM-ľ������ܳ�����
** ���� : tsingke
** ���� : 2020-10-19 / 08:38
** ��Ȩ : tsingke@sdnu.edu.cn
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
			�����������Ϣ
*-----------------------------------*/

//�����Ƿ񹹳�������
int isTriangle(const double &r1,const double &r2, const double&r3)
{
	if ((r1 + r2 > r3) && (r1 + r3 > r2) && (r2 + r3 > r1))
	{
		return 1;
	}
	else
		return 0;
}

//�����������ܳ�
double perimeter(const double &r1, const double &r2, const double&r3)
{
	return (r1 + r2 + r3);
}



//�������������
double area(const double &r1, const double &r2, const double&r3)
{

	double p = 0.5*(r1 + r2 + r3);


	return sqrt(p*(p - r1)*(p - r2)*(p - r3));


}




/*----------------------------------*
  �����ι����㷨:��һ��,���Ӷ�o(n^3))
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

						//��¼��ǰ�߳�
						perim_a = plen[i];
						perim_b = plen[j];
						perim_c = plen[k];

					}

					canConstructTriangle = true;//���ڹ��������ε�ľ��

				}

				else
					continue;
			}

		}
	}

	if (canConstructTriangle == false)
	{
		cout << "��ʾ: ��ǰľ�������޷������κ�������!" << endl;
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

						//��¼��ǰ�߳�
						area_a = plen[i];
						area_b = plen[j];
						area_c = plen[k];

					}



					canConstructTriangle = 1;//���ڹ��������ε�ľ��

				}

				else
					continue;
			}

		}
	}

	if (canConstructTriangle == 0)
	{
		cout << "��ʾ: ��ǰľ�������޷������κ�������!" << endl;
		return 0;

	}
	else
		return 1;


}

/*----------------------------------*
  �����ι����㷨:�ڶ���,���Ӷ�o(n^log(n)))
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

	//1. ����ľ�����ȴӴ�С����
	qsort(plen, num, sizeof(plen[0]), cmpfunc);


	//2. ����������,�������ܳ�
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

						//��¼��ǰ�߳�
						perim_a = plen[i];
						perim_b = plen[j];
						perim_c = plen[k];

					}

					canConstructTriangle = 1;//���ڹ��������ε�ľ��

					break;//�ҵ������ֹ����,������������

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
		  Main Function
*-----------------------------------*/

int main()
{


	/*----------------------------------*
		   1. ����ľ�������ͳ���
	*-----------------------------------*/
	cout << "-------------- �������� --------------" << endl;

	cout << "������ľ�����ܸ��� m = ";

	int m;
	cin >> m;

	// ��̬�����ڴ�ռ䣬�洢ľ������

	double *len = new double[m];

	cout << "����������" << m << "��ľ���ĳ���"<<endl;

	for (int i = 0; i < m; i++)
	{
		cout << "len[" << i << "] = ";
		cin >> len[i];


	}
	

	cout <<endl<<"-------------- ������ --------------" << endl;


	/*----------------------------------*
	      2. ��������ܳ�,������ܳ�
	*-----------------------------------*/


	//int success = searchMaxLength(len, m); //���Ӷȸ�
	int length_success = searchMaxLength_log(len, m);//���Ӷȵ�

	if (length_success == 1)
	{
		cout << "����ܳ�: " << maxPerimeter << " (�߳�Ϊ: " << perim_a << "," << perim_b << "," << perim_c << ")" << endl;

	}
	else
	{
		cout << 0 << endl;
		cout << "��ʾ: ��ǰľ�������޷������κ�������!" << endl;
	}
	

	/*----------------------------------*
		  3. ����������,��������
	*-----------------------------------*/

	int area_success = searchMaxArea(len, m);

	if (area_success == 1)
	{
		cout << "������: " << maxArea << " (�߳�Ϊ: " << area_a << "," << area_b << "," << area_c << ")" << endl << endl;

	}
	else
	{
		cout << 0 << endl;
		cout << "��ʾ: ��ǰľ�������޷������κ�������!"<<endl;
	}



	/*----------------------------------*
	       4.�ͷŶ�̬�ڴ�ռ�
	*-----------------------------------*/


	delete[] len;


	system("pause");

	return 0;
}