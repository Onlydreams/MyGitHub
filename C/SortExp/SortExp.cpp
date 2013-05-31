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

//辅助交换函数
void swap(double &a, double &b)
{
	double t;
	t = a;
	a = b;
	b = t;
}

//归并排序
void merge(double A[], int low, int mid, int high)//归并操作
{
	int n1, n2, i, j, k;
    double *left=NULL, *right=NULL;
 
    n1 = mid - low + 1; 
	n2 = high - mid;
 
    left = (double *)malloc(sizeof(double)*(n1)); 
    right = (double *)malloc(sizeof(double)*(n2));
    for(i=0; i<n1; i++) 
		left[i] = A[low+i];
    for(j=0; j<n2; j++)  
		right[j] = A[mid+1+j];
 
    i = j = 0; 
	k = low;
    while(i<n1 && j<n2) 
    {
		if(left[i] <= right[j])
			A[k++] = left[i++];
		else
			A[k++] = right[j++];
    }
 
    for(; i<n1; i++) 
		A[k++] = left[i];
    for(; j<n2; j++) 
		A[k++] = right[j];
}
 
void MergeSort(double A[], int low, int high)
{
    int mid;
    if(low < high)
    {
		mid = (int)((low+high)/2);        
		MergeSort(A, low, mid);  
		MergeSort(A, mid+1, high);
		merge(A, low, mid, high);
    }
}

//插入排序
void InsertionSort(double A[],int n)
{
	int i,j;
	double key;
	for(j=1;j<n;j++)
	{
		key = A[j];
		i = j -1;
		while(i>=0 && key<A[i])//找到插入位置，将后面的依次后移
		{
			A[i+1] = A[i];
			i = i-1;
		}
		A[i+1] = key;
	}
}

//希尔排序
void ShellSort(double A[], int n)
{
	int d;
	double temp;
	for(d=n/2; d>0; d/=2)//以数组长度一半为起始步长
	{
		for(int i = d; i<n; i++)
		{
			for(int j=i-d; i-d>0 && A[j]<A[j-d]; j-=d)
				swap(A[j], A[j-d]);
		}
	}
}

//快速排序
int Partition(double A[], int p, int q)//划分操作
{
	int i,j;
	double povit;
	povit = A[p];//以第一个元素为枢轴
	i = p;
	for(j = p+1;j <= q;j++)
	{
		if(povit >= A[j])
		{
			i = i + 1;
			swap(A[i],A[j]);
		}
	}
	swap(A[p],A[i]);
	return i;
}
void QuickSort(double A[], int p, int q)
{
	if(p < q)
	{
		int r = Partition(A, p, q);
		QuickSort(A, p, r-1);
		QuickSort(A, r+1, q);
	}
}

//冒泡排序
void BubbleSort(double A[], int n)
{
	int i, j;
	int flag = 0;//使用标志位减少比较次数
	for(i=0; i<n; i++)
	{
		for(j=1; j<n-i; j++)
		{
			if(A[j] < A[j-1])
			{
				swap(A[j], A[j-1]);
				flag = 1;
			}
		}
		if(flag == 0)
				break;
	}
}

int main()
{
	double rand_num1[SMALL];
	double rand_num2[MID];
	double rand_num3[BIG];
	double rand_num4[HUGE];
	srand((unsigned)time(0));
	//用随机数初始化数组
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
	MergeSort(rand_num4, 0, HUGE-1);
	clockEnd_merge = clock();
	printf("%d\n", clockEnd_merge - clockBegin_merge);
	
	clock_t clockBegin_insertion, clockEnd_insertion;
	clockBegin_insertion = clock();
	InsertionSort(rand_num3, BIG);
	clockEnd_insertion = clock();
	printf("%d\n", clockEnd_insertion - clockBegin_insertion);

	ShellSort(rand_num1, SMALL);
	for(int i=0; i<SMALL; ++i)    
        cout<<rand_num1[i]<<" "<<endl;
	QuickSort(rand_num2, 0, MID-1);
	for(int i=0; i<MID; ++i)    
        cout<<rand_num2[i]<<" "<<endl;

}