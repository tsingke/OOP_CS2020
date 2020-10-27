/*************************************************
** ���� : ���ö��ַ������⺯��f(x)��һ�����
** ���� : tsingke
** ���� : 2020-10-27
** ��Ȩ : tsingke@sdnu.edu.cn
/**************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std;

const double eps = 1e-6;



/*----------------------------------*
*             �����Ӻ���
*-----------------------------------*/

//����: ���������ĳ������f(x)
double function(double x)
{
	double temp = 1.56*pow(x - 1, 6) - 3.128*pow(x - 2, 4) + 2.85 * pow(x, 4) + 15 * pow(x, 3) - 2.645 * pow(x, 2) + 274 * x - 24;

	return temp;

}


//����: ���ö��ַ�Ѱ�����⺯����һ�����(ʵ��)
double binarySearch(double &left, double &right)
{
	int count = 0;

	double middle = 0.5*(left + right);



	while (fabs(function(middle)) > eps)
	{
		cout << "��ʼ��" << ++count << "������..." << endl;

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
*               ������
*-----------------------------------*/

int main()
{
	cout << "******���ַ���⺯�������������ֵ******" << endl;

	double xmin, xmax;
	double randx1, randx2;


	// 1. ���뺯���Ա���������Χ
	cout << "������������߽�xmin = "; cin >> xmin;
	cout << "�����������ұ߽�xmax = "; cin >> xmax;



	//2. ��������Χ��Ѱ�����������,ʹ�����ǵĺ���ֵ���Ų�ͬ
	srand(int(time(NULL))); //�������������
	do
	{
		randx1 = xmin + rand() / (RAND_MAX + 1.0)*(xmax - xmin);
		randx2 = xmin + rand() / (RAND_MAX + 1.0)*(xmax - xmin);

	} while (function(randx1)*function(randx2) > 0);
	

	//3.������[randx1,randx2]��Χ�ڲ��ö��ַ������������̵�һ����(���)
	double root = binarySearch(randx1, randx2);



	//4. ������������
	cout << "��ϲ,������������f(x)=0��1����, x = " << setprecision(10)<<root << endl;




	system("pause");

	return 0;
}