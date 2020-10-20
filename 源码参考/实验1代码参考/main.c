#define  _CRT_SECURE_NO_WARNINGS

/*************************************************
** ���� : ѧ���ɼ�����ϵͳ
** ���� : Qingke Zhang/tsingke@sdnu.edu.cn
** �汾 : v1.0
** ��Ȩ : GNU General Public License(GNU GPL)
/**************************************************/


#include <stdio.h>
#include "score.h"
#include <windows.h>


/*----------------------------------*
		Main Function
*-----------------------------------*/

int main()
{

	printf("******************************\n");
	printf("       ѧ���ɼ��������ϵͳ        \n");
	printf("         Qingke Zhang            \n");
	printf("******************************\n\n");


	/*-1.������ʼ��-*/
	int N = 0;            //ѧ������
	SS  *pstu = NULL;    //ѧ������-�ṹ������ָ��ʵ��

	double meanScore = 0.0;
	double stdScore = 0.0;

	//2.��ȡѧ����Ϣ
	pstu = readDataFromFile(&N);

	/*-3.����ѧ���ܳɼ����ܳɼ� = 0.2*ƽʱ�ɼ� + 0.8*��ĩ�ɼ�)--*/
	calcuScore(pstu, N);

	/*-4.����ѧ���ɼ�����-*/
	sortScore(pstu, N);

	/*-5.�����������ѧ����Ϣ-*/
	printOut(pstu, N);

	/*-6.����ѧ���ɼ��ľ�ֵ�ͷ���-*/
	statistic(pstu, N, &meanScore, &stdScore);
	/*cout << "ѧ���ɼ���ֵΪ: " << meanScore << " ����Ϊ: " << stdScore << endl;*/
	printf("ѧ����ƽ���ɼ�Ϊ:%.4f, �ɼ���׼����Ϊ:%.4f\n", meanScore, stdScore);

	/*-7. �ɼ���������(����ѧ������)-*/

	char stuid[20];
	printf("������Ҫ��ѯ��ѧ����ѧ��id= ");
	scanf("%s", stuid);
	search(pstu, N, stuid);


	/*-8.�ͷŶ�̬�ڴ�ռ�-*/
	free(pstu);


	system("pause");
	return 0;
}



