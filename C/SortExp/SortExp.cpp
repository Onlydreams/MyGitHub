// SortExp.cpp : Compare the normal sort algorithm
//

#include<iostream>
#include<ctime>
#include<Windows.h>
using namespace std;

#define SMALL 10
#define MID 1000
#define BIG 10000
#define HUGE 100000

//�鲢����
void merge(double A[], int low, int mid, int high)
{
	int n1, n2, i, j, k;
    double *left=NULL, *right=NULL;
 
    n1 = mid - low + 1; 
	n2 = high - mid;
 
    left = (double *)malloc(sizeof(double)*(n1)); 
    right = (double *)malloc(sizeof(double)*(n2));
    for(i=0; i<n1; i++)  //�������鸳ֵ
		left[i] = A[low+i];
    for(j=0; j<n2; j++)  //�������鸳ֵ
		right[j] = A[mid+1+j];
 
    i = j = 0; 
	k = low;
    while(i<n1 && j<n2) //������Ԫ��ֵ�����Ƚϣ����ϲ�������A
    {
		if(left[i] <= right[j])
			A[k++] = left[i++];
		else
			A[k++] = right[j++];
    }
 
    for(; i<n1; i++) //�����������Ԫ��ʣ�࣬��ʣ��Ԫ�غϲ�������A
		A[k++] = left[i];
    for(; j<n2; j++) //�����������Ԫ��ʣ�࣬��ʣ��Ԫ�غϲ�������A
		A[k++] = right[j];
}
 
void mergeSort(double A[], int low, int high)
{
    int mid;
    if(low < high) //ֻ��һ�����޼�¼ʱ�������� 
    {
		mid = (int)((low+high)/2);      //������A�ֳ�����   
		mergeSort(A, low, mid);   //�ݹ���������
		mergeSort(A, mid+1, high); //�ݹ���������
		merge(A, low, mid, high);    //�ϲ�����
    }
}

//��������
void InsertionSort(double A[],int n)
{
	int i,j;
	double key;
	for(j=1;j<n;j++)
	{
		key = A[j];
		i = j -1;
		while(i>=0 && key<A[i])//�ҵ�����λ�ã�����������κ���
		{
			A[i+1] = A[i];
			i = i-1;
		}
		A[i+1] = key;
	}
}

//ϣ������
void shellSort(double A[], int n)
{
	int d;
	double temp;
	for(d=n/2; d>0; d/=2)//�����鳤��һ��Ϊ��ʼ����
	{
		for(int i = d; i<n; i++)
		{
			for(int j=i-d; i-d>0 && A[j]<A[j-d]; j-=d)
			{
				temp = A[j];
				A[j] = A[j-d];
				A[j-d] = temp;
			}
		}
	}
}

int main()
{
	double rand_num1[SMALL];
	double rand_num2[MID];
	double rand_num3[BIG];
	double rand_num4[HUGE];
	srand((unsigned)time(0));
	//���������ʼ������
	for(int i=0;i<SMALL;i++)
	{  
		rand_num1[i]=rand() / double(RAND_MAX); 
	}
	for(int i=0;i<MID;i++)
	{  
		rand_num2[i]=rand() / double(RAND_MAX); 
	}
	for(int i=0;i<BIG;i++)
	{  
		rand_num3[i]=rand() / double(RAND_MAX); 
	}
	for(int i=0;i<HUGE;i++)
	{  
		rand_num4[i]=rand() / double(RAND_MAX); 
	}
	
	clock_t  clockBegin_merge, clockEnd_merge;
	clockBegin_merge = clock();
	mergeSort(rand_num4, 0, HUGE-1);
	clockEnd_merge = clock();
	printf("%d\n", clockEnd_merge - clockBegin_merge);
	
	clock_t clockBegin_insertion, clockEnd_insertion;
	clockBegin_insertion = clock();
	InsertionSort(rand_num3, BIG);
	clockEnd_insertion = clock();
	printf("%d\n", clockEnd_insertion - clockBegin_insertion);

	shellSort(rand_num1, SMALL);
	for(int i=0; i<SMALL; ++i)    
        cout<<rand_num1[i]<<" ";

}
