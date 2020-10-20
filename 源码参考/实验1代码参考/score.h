/*************************************************
* Head File   : score.h
* Create Time : 2020-10-20
/**************************************************/

#ifndef __SCORE_H__
#define __SCORE_H__

/*----------------------------------*
	   学生信息-结构体设计
*-----------------------------------*/

typedef struct student
{
	char number[20];  //学号
	char name[20];    //姓名
	float dailyScore;   //平时成绩
	float experiScore; //实验成绩
	float examScore;   //期末成绩
	float finalScore;   //期末成绩
	

}SS;

/*----------------------------------*
	Function Declaration
*-----------------------------------*/
/*---------------函数声明-------------------*/

//1.读取学生基本数据
void InputData(SS stu[], int N);
SS* readDataFromFile(int *N);

//2-1.计算N个学生各自总成绩
void calcuScore(SS stu[], int N);

//2-2. 计算成绩的均值和方差
void statistic(SS stu[], int N, double *mean, double *std);


//3.根据总评成绩排名
void sortScore(SS stu[], int N);


//4.按照一定的格式输出N个学生的完整信息
void printOut(SS stu[], int N);

	
//5. 根据学号查询学生的数据
int search(SS stu[], int N, char *id);



#endif

