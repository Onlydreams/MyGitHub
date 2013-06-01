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
	for(d=n/2; d>0; d/=2)//以数组长度一半为起始步长
	{
		for(int i = d; i<n; i++)
		{
			for(int j=i-d; j>=0 && A[j]>A[j+d]; j-=d)
				swap(A[j], A[j+d]);
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

//桶排序
typedef struct node{//辅助链表节点结构
	double data;
	struct node *next;
}node;



void bucket_insert(struct node *des, struct node *ins)//定义桶内链表节点插入操作
{
	struct node* p = des;
	struct node* q = des;
	if(!p->next)
		p->next = ins;
	else 
	{
		p = p->next;
		while(p && p->data<=ins->data)
		{
			p = p->next;
			q = q->next;
		}
		if(!p)
			q->next = ins;
		else
		{
			q->next = ins;
			ins->next = p;
		}
	}
}

void BucketSort(double A[], int n)
{
	node *B = new node[n];
	for(int k=0; k<n; k++)
		B[k].next = NULL;
	int i,j;
	int s = 0;
	for(i=0; i<n; i++)
	{
		j = A[i] * n;
		node *p = (struct node*)malloc(sizeof(node));
		p->next = NULL;
		p->data = A[i];
		bucket_insert(&B[j], p);
	}

	for(i=0;i<n;i++)
	{	
		node *t;
		t = &B[i];
		while(t->next)
			{  
				t = t->next;
				A[s] = t->data;
				s++;
			}
	}
}

int main()
{
	double *small_rand = new double[SMALL];
	double *s1 = new double[SMALL];
	double *s2 = new double[SMALL];
	double *s3 = new double[SMALL];
	double *s4 = new double[SMALL];
	double *s5 = new double[SMALL];
	double *s6 = new double[SMALL];

	double *mid_rand = new double[MID];
	double *m1 = new double[MID];
	double *m2 = new double[MID];
	double *m3 = new double[MID];
	double *m4 = new double[MID];
	double *m5 = new double[MID];
	double *m6 = new double[MID];

	double *big_rand = new double[BIG];
	double *b1 = new double[BIG];
	double *b2 = new double[BIG];
	double *b3 = new double[BIG];
	double *b4 = new double[BIG];
	double *b5 = new double[BIG];
	double *b6 = new double[BIG];

	double *huge_rand = new double[HUGE];
	double *h1 = new double[HUGE];
	double *h2 = new double[HUGE];
	double *h3 = new double[HUGE];
	double *h4 = new double[HUGE];
	double *h5 = new double[HUGE];
	double *h6 = new double[HUGE];
	
	srand((unsigned)time(0));
	//用随机数初始化数组
	for(int i=0;i<SMALL;i++)
	{  
		small_rand[i] = rand() / double(RAND_MAX);
		s1[i] = small_rand[i];
		s2[i] = small_rand[i];
		s3[i] = small_rand[i];
		s4[i] = small_rand[i];
		s5[i] = small_rand[i];
		s6[i] = small_rand[i];
	}
	for(int i=0;i<MID;i++)
	{  
		mid_rand[i] = rand() / double(RAND_MAX);
		m1[i] = mid_rand[i];
		m2[i] = mid_rand[i];
		m3[i] = mid_rand[i];
		m4[i] = mid_rand[i];
		m5[i] = mid_rand[i];
		m6[i] = mid_rand[i];
	}
	for(int i=0;i<BIG;i++)
	{  
		big_rand[i] = rand() / double(RAND_MAX);
		b1[i] = big_rand[i];
		b2[i] = big_rand[i];
		b3[i] = big_rand[i];
		b4[i] = big_rand[i];
		b5[i] = big_rand[i];
		b6[i] = big_rand[i];
	}
	for(int i=0;i<HUGE;i++)
	{  
		huge_rand[i] = rand() / double(RAND_MAX);
		h1[i] = huge_rand[i];
		h2[i] = huge_rand[i];
		h3[i] = huge_rand[i];
		h4[i] = huge_rand[i];
		h5[i] = huge_rand[i];
		h6[i] = huge_rand[i];
	}

	//(1)n=10时排序结果
	for(int i=0; i<SMALL; i++)
	{
		cout<<small_rand[i]<<" ";
	}
	cout<<endl;
	MergeSort(s1, 0, SMALL - 1);
	for(int i=0; i<SMALL; i++)
	{
		cout<<s1[i]<<" ";
	}
	cout<<endl;
	InsertionSort(s2, SMALL);
	for(int i=0; i<SMALL; i++)
	{
		cout<<s2[i]<<" ";
	}
	cout<<endl;
	ShellSort(s3, SMALL);
	for(int i=0; i<SMALL; i++)
	{
		cout<<s3[i]<<" ";
	}
	cout<<endl;
	QuickSort(s4, 0, SMALL - 1);
	for(int i=0; i<SMALL; i++)
	{
		cout<<s4[i]<<" ";
	}
	cout<<endl;
	BubbleSort(s5, SMALL);
	for(int i=0; i<SMALL; i++)
	{
		cout<<s5[i]<<" ";
	}
	cout<<endl;
	BucketSort(s6, SMALL);
	for(int i=0; i<SMALL; i++)
	{
		cout<<s6[i]<<" ";
	}
	cout<<endl;

	clock_t  clockBegin_bucket, clockEnd_bucket;
	clockBegin_bucket = clock();
	BucketSort(h4, HUGE);
	clockEnd_bucket = clock();
	cout<<(clockEnd_bucket - clockBegin_bucket)*1000 / CLOCKS_PER_SEC<<"ms"<<endl;
	clock_t  clockBegin_shell, clockEnd_shell;
	clockBegin_shell = clock();
	ShellSort(h5, HUGE);
	clockEnd_shell = clock();
	cout<<(clockEnd_shell - clockBegin_shell)*1000 / CLOCKS_PER_SEC<<"ms"<<endl;
	

	delete []small_rand;
	delete []s1;
	delete []s2;
	delete []s3;
	delete []s4;
	delete []s5;
	delete []s6;

	delete []mid_rand;
	delete []m1;
	delete []m2;
	delete []m3;
	delete []m4;
	delete []m5;
	delete []m6;

	delete []big_rand;
	delete []b1;
	delete []b2;
	delete []b3;
	delete []b4;
	delete []b5;
	delete []b6;

	delete []huge_rand;
	delete []h1;
	delete []h2;
	delete []h3;
	delete []h4;
	delete []h5;
	delete []h6;

	return 0;
}