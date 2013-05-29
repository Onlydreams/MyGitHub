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

//归并排序
void merge(double *data, int low, int mid, int high)
{
	int n1, n2, i, j, k;
    double *left=NULL, *right=NULL;
 
    n1 = mid - low + 1; 
	n2 = high - mid;
 
    left = (double *)malloc(sizeof(double)*(n1)); 
    right = (double *)malloc(sizeof(double)*(n2));
    for(i=0; i<n1; i++)  //对左数组赋值
		left[i] = data[low+i];
    for(j=0; j<n2; j++)  //对右数组赋值
		right[j] = data[mid+1+j];
 
    i = j = 0; 
	k = low;
    while(i<n1 && j<n2) //将数组元素值两两比较，并合并到data数组
    {
		if(left[i] <= right[j])
			data[k++] = left[i++];
		else
			data[k++] = right[j++];
    }
 
    for(; i<n1; i++) //如果左数组有元素剩余，则将剩余元素合并到data数组
		data[k++] = left[i];
    for(; j<n2; j++) //如果右数组有元素剩余，则将剩余元素合并到data数组
		data[k++] = right[j];
}
 
void mergeSort(double *data, int low, int high)
{
    int mid;
    if(low < high) //只有一个或无记录时不须排序 
    {
		mid = (int)((low+high)/2);      //将data数组分成两半   
		mergeSort(data, low, mid);   //递归拆分左数组
		mergeSort(data, mid+1, high); //递归拆分右数组
		merge(data, low, mid, high);    //合并数组
    }
}

//插入排序
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

//希尔排序


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
