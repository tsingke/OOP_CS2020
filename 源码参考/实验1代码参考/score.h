/*************************************************
* Head File   : score.h
* Create Time : 2020-10-20
/**************************************************/

#ifndef __SCORE_H__
#define __SCORE_H__

/*----------------------------------*
	   ѧ����Ϣ-�ṹ�����
*-----------------------------------*/

typedef struct student
{
	char number[20];  //ѧ��
	char name[20];    //����
	float dailyScore;   //ƽʱ�ɼ�
	float experiScore; //ʵ��ɼ�
	float examScore;   //��ĩ�ɼ�
	float finalScore;   //��ĩ�ɼ�
	

}SS;

/*----------------------------------*
	Function Declaration
*-----------------------------------*/
/*---------------��������-------------------*/

//1.��ȡѧ����������
void InputData(SS stu[], int N);
SS* readDataFromFile(int *N);

//2-1.����N��ѧ�������ܳɼ�
void calcuScore(SS stu[], int N);

//2-2. ����ɼ��ľ�ֵ�ͷ���
void statistic(SS stu[], int N, double *mean, double *std);


//3.���������ɼ�����
void sortScore(SS stu[], int N);


//4.����һ���ĸ�ʽ���N��ѧ����������Ϣ
void printOut(SS stu[], int N);

	
//5. ����ѧ�Ų�ѯѧ��������
int search(SS stu[], int N, char *id);



#endif

