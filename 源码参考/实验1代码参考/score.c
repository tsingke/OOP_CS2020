/*************************************************
** Դ�ļ�   : score.c
** ����˵�� : Function Definations
** ����ʱ�� : 2020-10-20
/**************************************************/
#define  _CRT_SECURE_NO_WARNINGS

/*----------------ͷ�ļ�--------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "score.h"


/*----------------��������-------------*/


//1.1�ֶ�����ѧ����������
void InputData(SS stu[], int N)
{

	printf("�밴�����¸�ʽ����ѧ����Ϣ��ѧ��,����,ƽʱ�ɼ�,��ĩ�ɼ�\n");

	for (int i = 0; i < N; i++)
	{
		printf("��%d��ѧ��:", i + 1);
		scanf("%s %s %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].finalScore);
		printf("\n");
	}

	printf("------�ɼ�¼�����!--------\n");

}

//1.2���ļ����ȡѧ����������
SS* readDataFromFile(int *N)
{

	printf("\n\n------��һ��: ���ļ���ȡѧ���ĳɼ���Ϣ--------\n\n");

	SS *stu;// �����¿ռ�,��ȡ�ļ��е�ÿ��ѧ����Ϣ

	FILE *fp = NULL;
	int count = 0;
	int index = 0;

	fp = fopen("data.txt", "r");

	//1.��ȡѧ����Ŀ
	if (fp != NULL)
	{
		fscanf(fp, "%d", &count);
		*N = count;
	}
	else
	{
		printf("failed to open the info file\n");
		getchar();
	}

	printf("ѧ����ĿΪ:%d\n", count);


	//2.������ѧ������洢�ռ�
	stu = (SS*)malloc(count * sizeof(SS));


	//3.��ȡÿ��ѧ������Ϣ
	while ((!feof(fp)))
	{

		//�����ļ����ݵ��ڴ�	
		fscanf(fp, "%s%s%f%f%f\n", (stu[index].number), (stu[index].name), &stu[index].dailyScore, &stu[index].experiScore,&stu[index].examScore);

		//���������ѧ����Ϣ
		printf("* ѧ�ţ�%s	����:%s	ƽʱ�ɼ���%4.2f��	 ʵ��ɼ�%4.2f	 ��ĩ�ɼ�:%4.2f��\n", (stu[index].number), (stu[index].name), stu[index].dailyScore, stu[index].experiScore,stu[index].examScore);

		index++;
	}

	getchar();

	fclose(fp);

	return stu;
}

//2.1 ����N��ѧ�����Ե������ɼ�
void calcuScore(SS stu[], int N)
{


	printf("\n\n------�ڶ���: ����ÿ��ѧ���������ɼ�--------\n\n");

	for (int i = 0; i < N; i++)
	{

		stu[i].finalScore = 0.2*stu[i].dailyScore+ 0.2*stu[i].experiScore+0.6*stu[i].examScore;
		printf("* ѧ�ţ�%s	����:%s	  �ܳɼ�:%4.2f��\n", (stu[i].number), (stu[i].name), stu[i].finalScore);

	}

	getchar();
}

//2.2 ����ѧ���ɼ��ľ�ֵ�ͷ���
void statistic(SS stu[], int N, double *mean, double *std)
{

	double sum = 0.0;

	//�����ֵ

	for (int i = 0; i < N; i++)
	{

		sum += stu[i].finalScore;

	}

	*mean = 1.0*sum / N ;

	//�����׼����
	sum = 0.0;
	for (int i = 0; i < N; i++)
	{
		sum += pow(stu[i].finalScore - *mean, 2);//����ƽ����

	}

	*std = sqrt(1.0*sum / N);


}


//3.���������ɼ�����
int cmpBigtoSmall(const void *a, const void *b)
{

	SS *aa = (SS *)(a);
	SS *bb = (SS *)(b);


	return ((*aa).finalScore < (*bb).finalScore);


}

void sortScore(SS stu[], int N)
{

	qsort(&(stu[0]), N, sizeof(stu[0]), cmpBigtoSmall);

}

//4.����һ���ĸ�ʽ���N��ѧ������Ϣ
void printOut(SS stu[], int N)
{

	printf("\n------������: �����ܳɼ����ѧ��������Ϣ!------\n\n");

	for (int i = 0; i < N; i++)
	{

		printf("��%d����Ϣ ѧ�ţ�%s	����:%s		�ܳɼ�:%4.2f��\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].finalScore);
	}

	getchar();

}

//5. ��ѯѧ����Ϣ

int search(SS stu[], int N, char *id)
{
	int flag = 0;

	for (int i = 0; i < N; i++)
	{

		if (strcmp(stu[i].number, id) == 0)
		{
			printf("ѧ�ţ�%s		����:%s		�ܳɼ�:%.4f��\n", &(stu[i].number[0]), &(stu[i].name[0]), stu[i].finalScore);

			flag = 1;
		
			break;
		}
		else
			continue;

	}

	if (flag == 0)
	{
		printf("�޴�ѧ����Ϣ,����ѧ�������Ƿ�׼ȷ!\n");
		return 0;

	}
	else
		return 1;



}