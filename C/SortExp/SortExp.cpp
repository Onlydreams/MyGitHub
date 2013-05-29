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
void merge(double *data, int low, int mid, int high)
{
	int n1, n2, i, j, k;
    double *left=NULL, *right=NULL;
 
    n1 = mid - low + 1; 
	n2 = high - mid;
 
    left = (double *)malloc(sizeof(double)*(n1)); 
    right = (double *)malloc(sizeof(double)*(n2));
    for(i=0; i<n1; i++)  //�������鸳ֵ
		left[i] = data[low+i];
    for(j=0; j<n2; j++)  //�������鸳ֵ
		right[j] = data[mid+1+j];
 
    i = j = 0; 
	k = low;
    while(i<n1 && j<n2) //������Ԫ��ֵ�����Ƚϣ����ϲ���data����
    {
		if(left[i] <= right[j])
			data[k++] = left[i++];
		else
			data[k++] = right[j++];
    }
 
    for(; i<n1; i++) //�����������Ԫ��ʣ�࣬��ʣ��Ԫ�غϲ���data����
		data[k++] = left[i];
    for(; j<n2; j++) //�����������Ԫ��ʣ�࣬��ʣ��Ԫ�غϲ���data����
		data[k++] = right[j];
}
 
void mergeSort(double *data, int low, int high)
{
    int mid;
    if(low < high) //ֻ��һ�����޼�¼ʱ�������� 
    {
		mid = (int)((low+high)/2);      //��data����ֳ�����   
		mergeSort(data, low, mid);   //�ݹ���������
		mergeSort(data, mid+1, high); //�ݹ���������
		merge(data, low, mid, high);    //�ϲ�����
    }
}

//��������
void insertionSort(double A[],int n)
{
	int i,j;
	double key;
	for(j=1;j<n;j++)
	{
		key = A[j];
		i = j -1;
		while(i>=0 && key<A[i])
		{
			A[i+1] = A[i];
			i = i-1;
		}
		A[i+1] = key;
	}
}

//ϣ������


int main()
{
	double rand_small[SMALL];
	double rand_mid[MID];
	double rand_big[BIG];
	double rand_huge[HUGE];
	srand((unsigned)time(0));
	
	for(int i=0;i<SMALL;i++)
	{  
		rand_small[i]=rand() / double(RAND_MAX); 
	}
	for(int i=0;i<MID;i++)
	{  
		rand_mid[i]=rand() / double(RAND_MAX); 
	}
	for(int i=0;i<BIG;i++)
	{  
		rand_big[i]=rand() / double(RAND_MAX); 
	}
	for(int i=0;i<HUGE;i++)
	{  
		rand_huge[i]=rand() / double(RAND_MAX); 
	}
	
	clock_t  clockBegin_merge, clockEnd_merge;
	clockBegin_merge = clock();
	mergeSort(rand_huge, 0, HUGE-1);
	clockEnd_merge = clock();
	printf("%d\n", clockEnd_merge - clockBegin_merge);
	
	clock_t clockBegin_insertion, clockEnd_insertion;
	clockBegin_insertion = clock();
	insertionSort(rand_huge, HUGE);
	clockEnd_insertion = clock();
	printf("%d\n", clockEnd_insertion - clockBegin_insertion);

}
