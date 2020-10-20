/*************************************************
** 源文件   : score.c
** 功能说明 : Function Definations
** 创建时间 : 2020-10-20
/**************************************************/
#define  _CRT_SECURE_NO_WARNINGS

/*----------------头文件--------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "score.h"


/*----------------函数定义-------------*/


//1.1手动输入学生基本数据
void InputData(SS stu[], int N)
{

	printf("请按照如下格式输入学生信息：学号,姓名,平时成绩,期末成绩\n");

	for (int i = 0; i < N; i++)
	{
		printf("第%d个学生:", i + 1);
		scanf("%s %s %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].finalScore);
		printf("\n");
	}

	printf("------成绩录入完毕!--------\n");

}

//1.2从文件里读取学生基本数据
SS* readDataFromFile(int *N)
{

	printf("\n\n------第一步: 从文件读取学生的成绩信息--------\n\n");

	SS *stu;// 开辟新空间,存取文件中的每个学生信息

	FILE *fp = NULL;
	int count = 0;
	int index = 0;

	fp = fopen("data.txt", "r");

	//1.获取学生数目
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

	printf("学生数目为:%d\n", count);


	//2.给所有学生分配存储空间
	stu = (SS*)malloc(count * sizeof(SS));


	//3.读取每条学生的信息
	while ((!feof(fp)))
	{

		//读入文件数据到内存	
		fscanf(fp, "%s%s%f%f%f\n", (stu[index].number), (stu[index].name), &stu[index].dailyScore, &stu[index].experiScore,&stu[index].examScore);

		//输出排序后的学生信息
		printf("* 学号：%s	姓名:%s	平时成绩：%4.2f分	 实验成绩%4.2f	 期末成绩:%4.2f分\n", (stu[index].number), (stu[index].name), stu[index].dailyScore, stu[index].experiScore,stu[index].examScore);

		index++;
	}

	getchar();

	fclose(fp);

	return stu;
}

//2.1 计算N个学生各自的总评成绩
void calcuScore(SS stu[], int N)
{


	printf("\n\n------第二步: 计算每个学生的总评成绩--------\n\n");

	for (int i = 0; i < N; i++)
	{

		stu[i].finalScore = 0.2*stu[i].dailyScore+ 0.2*stu[i].experiScore+0.6*stu[i].examScore;
		printf("* 学号：%s	姓名:%s	  总成绩:%4.2f分\n", (stu[i].number), (stu[i].name), stu[i].finalScore);

	}

	getchar();
}

//2.2 计算学生成绩的均值和方差
void statistic(SS stu[], int N, double *mean, double *std)
{

	double sum = 0.0;

	//计算均值

	for (int i = 0; i < N; i++)
	{

		sum += stu[i].finalScore;

	}

	*mean = 1.0*sum / N ;

	//计算标准方差
	sum = 0.0;
	for (int i = 0; i < N; i++)
	{
		sum += pow(stu[i].finalScore - *mean, 2);//计算平方和

	}

	*std = sqrt(1.0*sum / N);


}


//3.根据总评成绩排名
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

//4.按照一定的格式输出N个学生的信息
void printOut(SS stu[], int N)
{

	printf("\n------第三步: 根据总成绩输出学生排名信息!------\n\n");

	for (int i = 0; i < N; i++)
	{

		printf("第%d名信息 学号：%s	姓名:%s		总成绩:%4.2f分\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].finalScore);
	}

	getchar();

}

//5. 查询学生信息

int search(SS stu[], int N, char *id)
{
	int flag = 0;

	for (int i = 0; i < N; i++)
	{

		if (strcmp(stu[i].number, id) == 0)
		{
			printf("学号：%s		姓名:%s		总成绩:%.4f分\n", &(stu[i].number[0]), &(stu[i].name[0]), stu[i].finalScore);

			flag = 1;
		
			break;
		}
		else
			continue;

	}

	if (flag == 0)
	{
		printf("无此学生信息,请检查学号输入是否准确!\n");
		return 0;

	}
	else
		return 1;



}