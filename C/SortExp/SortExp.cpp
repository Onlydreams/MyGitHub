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

//������������
void swap(double &a, double &b)
{
	double t;
	t = a;
	a = b;
	b = t;
}

//�鲢����
void merge(double A[], int low, int mid, int high)//�鲢����
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
void ShellSort(double A[], int n)
{
	int d;
	for(d=n/2; d>0; d/=2)//�����鳤��һ��Ϊ��ʼ����
	{
		for(int i = d; i<n; i++)
		{
			for(int j=i-d; j>=0 && A[j]>A[j+d]; j-=d)
				swap(A[j], A[j+d]);
		}
	}
}

//��������
int Partition(double A[], int p, int q)//���ֲ���
{
	int i,j;
	double povit;
	povit = A[p];//�Ե�һ��Ԫ��Ϊ����
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

//ð������
void BubbleSort(double A[], int n)
{
	int i, j;
	int flag = 0;//ʹ�ñ�־λ���ٱȽϴ���
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

//Ͱ����
typedef struct node{//��������ڵ�ṹ
	double data;
	struct node *next;
}node;



void bucket_insert(struct node *des, struct node *ins)//����Ͱ������ڵ�������
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
	int total_m1 = 0;
	int total_m2 = 0;
	int total_m3 = 0;
	int total_m4 = 0;
	int total_m5 = 0;
	int total_m6 = 0;

	int total_b1 = 0;
	int total_b2 = 0;
	int total_b3 = 0;
	int total_b4 = 0;
	int total_b5 = 0;
	int total_b6 = 0;

	int total_h1 = 0;
	int total_h2 = 0;
	int total_h3 = 0;
	int total_h4 = 0;
	int total_h5 = 0;
	int total_h6 = 0;

	double *small_rand = new double[SMALL];
	double *s1 = new double[SMALL];
	double *s2 = new double[SMALL];
	double *s3 = new double[SMALL];
	double *s4 = new double[SMALL];
	double *s5 = new double[SMALL];
	double *s6 = new double[SMALL];

	
	srand((unsigned)time(0));
	//���������ʼ������
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

	//(1)n=10ʱ������
	cout<<"ԭʼ����Ϊ��";
	for(int i=0; i<SMALL; i++)
	{
		cout<<small_rand[i]<<" ";
	}
	cout<<endl;
	cout<<"�鲢�����Ľ����";
	MergeSort(s1, 0, SMALL - 1);
	for(int i=0; i<SMALL; i++)
	{
		cout<<s1[i]<<" ";
	}
	cout<<endl;
	cout<<"���������Ľ����";
	InsertionSort(s2, SMALL);
	for(int i=0; i<SMALL; i++)
	{
		cout<<s2[i]<<" ";
	}
	cout<<endl;
	cout<<"ϣ�������Ľ����";
	ShellSort(s3, SMALL);
	for(int i=0; i<SMALL; i++)
	{
		cout<<s3[i]<<" ";
	}
	cout<<endl;
	cout<<"���������Ľ����";
	QuickSort(s4, 0, SMALL - 1);
	for(int i=0; i<SMALL; i++)
	{
		cout<<s4[i]<<" ";
	}
	cout<<endl;
	cout<<"ð�������Ľ����";
	BubbleSort(s5, SMALL);
	for(int i=0; i<SMALL; i++)
	{
		cout<<s5[i]<<" ";
	}
	cout<<endl;
	cout<<"Ͱ�����Ľ����";
	BucketSort(s6, SMALL);
	for(int i=0; i<SMALL; i++)
	{
		cout<<s6[i]<<" ";
	}
	cout<<endl;

	int times = 5;
	for(int t=0; t<times; t++)
	{
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

	
		//(2)n=1000,10000,100000ʱ����ͬһ������ʵ������ͬ�����������ʱ��

		//n=1000ʱ
		cout<<"������СΪ1000ʱ��"<<endl;

		clock_t  clockBegin_merge1, clockEnd_merge1;
		clockBegin_merge1 = clock();
		MergeSort(m1, 0, MID-1);
		clockEnd_merge1 = clock();
		cout<<"��"<<t+1<<"�ι鲢��������ʱ��Ϊ"<<(clockEnd_merge1 - clockBegin_merge1)<<"ms"<<endl;
		total_m1 += (clockEnd_merge1 - clockBegin_merge1);

		clock_t  clockBegin_insert1, clockEnd_insert1;
		clockBegin_insert1 = clock();
		InsertionSort(m2, MID);
		clockEnd_insert1 = clock();
		cout<<"��"<<t+1<<"�β�����������ʱ��Ϊ"<<(clockEnd_insert1 - clockBegin_insert1)<<"ms"<<endl;
		total_m2 += (clockEnd_insert1 - clockBegin_insert1);

		clock_t  clockBegin_shell1, clockEnd_shell1;
		clockBegin_shell1 = clock();
		ShellSort(m3, MID);
		clockEnd_shell1 = clock();
		cout<<"��"<<t+1<<"��ϣ����������ʱ��Ϊ"<<(clockEnd_shell1 - clockBegin_shell1)<<"ms"<<endl;
		total_m3 += (clockEnd_shell1 - clockBegin_shell1);

		clock_t  clockBegin_quick1, clockEnd_quick1;
		clockBegin_quick1 = clock();
		QuickSort(m4, 0, MID-1);
		clockEnd_quick1 = clock();
		cout<<"��"<<t+1<<"�ο�����������ʱ��Ϊ"<<(clockEnd_quick1 - clockBegin_quick1)<<"ms"<<endl;
		total_m4 += (clockEnd_quick1 - clockBegin_quick1);

		clock_t  clockBegin_bubble1, clockEnd_bubble1;
		clockBegin_bubble1 = clock();
		BubbleSort(m5, MID);
		clockEnd_bubble1 = clock();
		cout<<"��"<<t+1<<"��ð����������ʱ��Ϊ"<<(clockEnd_bubble1 - clockBegin_bubble1)<<"ms"<<endl;
		total_m5 += (clockEnd_bubble1 - clockBegin_bubble1);

		clock_t  clockBegin_bucket1, clockEnd_bucket1;
		clockBegin_bucket1 = clock();
		BucketSort(m6, MID);
		clockEnd_bucket1 = clock();
		cout<<"��"<<t+1<<"��Ͱ��������ʱ��Ϊ"<<(clockEnd_bucket1 - clockBegin_bucket1)<<"ms"<<endl;
		total_m6 += (clockEnd_bucket1 - clockBegin_bucket1);

		//n=10000ʱ
		cout<<"������СΪ10000ʱ��"<<endl;

		clock_t  clockBegin_merge2, clockEnd_merge2;
		clockBegin_merge2 = clock();
		MergeSort(b1, 0, BIG-1);
		clockEnd_merge2 = clock();
		cout<<"��"<<t+1<<"�ι鲢��������ʱ��Ϊ"<<(clockEnd_merge2 - clockBegin_merge2)<<"ms"<<endl;
		total_b1 += (clockEnd_merge2 - clockBegin_merge2);

		clock_t  clockBegin_insert2, clockEnd_insert2;
		clockBegin_insert2 = clock();
		InsertionSort(b2, BIG);
		clockEnd_insert2 = clock();
		cout<<"��"<<t+1<<"�β�����������ʱ��Ϊ"<<(clockEnd_insert2 - clockBegin_insert2)<<"ms"<<endl;
		total_b2 += (clockEnd_insert2 - clockBegin_insert2);

		clock_t  clockBegin_shell2, clockEnd_shell2;
		clockBegin_shell2 = clock();
		ShellSort(b3, BIG);
		clockEnd_shell2 = clock();
		cout<<"��"<<t+1<<"��ϣ����������ʱ��Ϊ"<<(clockEnd_shell2 - clockBegin_shell2)<<"ms"<<endl;
		total_b3 += (clockEnd_shell2 - clockBegin_shell2);

		clock_t  clockBegin_quick2, clockEnd_quick2;
		clockBegin_quick2 = clock();
		QuickSort(b4, 0, BIG-1);
		clockEnd_quick2 = clock();
		cout<<"��"<<t+1<<"�ο�����������ʱ��Ϊ"<<(clockEnd_quick2 - clockBegin_quick2)<<"ms"<<endl;
		total_b4 += (clockEnd_quick2 - clockBegin_quick2);

		clock_t  clockBegin_bubble2, clockEnd_bubble2;
		clockBegin_bubble2 = clock();
		BubbleSort(b5, BIG);
		clockEnd_bubble2 = clock();
		cout<<"��"<<t+1<<"��ð����������ʱ��Ϊ"<<(clockEnd_bubble2 - clockBegin_bubble2)<<"ms"<<endl;
		total_b5 += (clockEnd_bubble2 - clockBegin_bubble2);

		clock_t  clockBegin_bucket2, clockEnd_bucket2;
		clockBegin_bucket2 = clock();
		BucketSort(b6, BIG);
		clockEnd_bucket2 = clock();
		cout<<"��"<<t+1<<"��Ͱ��������ʱ��Ϊ"<<(clockEnd_bucket2 - clockBegin_bucket2)<<"ms"<<endl;
		total_b6 += (clockEnd_bucket2 - clockBegin_bucket2);

		//n=10000ʱ
		cout<<"������СΪ100000ʱ��"<<endl;

		clock_t  clockBegin_merge3, clockEnd_merge3;
		clockBegin_merge3 = clock();
		MergeSort(h1, 0, HUGE-1);
		clockEnd_merge3 = clock();
		cout<<"��"<<t+1<<"�ι鲢��������ʱ��Ϊ"<<(clockEnd_merge3 - clockBegin_merge3)<<"ms"<<endl;
		total_h1 += (clockEnd_merge3 - clockBegin_merge3);

		clock_t  clockBegin_insert3, clockEnd_insert3;
		clockBegin_insert3 = clock();
		InsertionSort(h2, HUGE);
		clockEnd_insert3 = clock();
		cout<<"��"<<t+1<<"�β�����������ʱ��Ϊ"<<(clockEnd_insert3 - clockBegin_insert3)<<"ms"<<endl;
		total_h2 += (clockEnd_insert3 - clockBegin_insert3);

		clock_t  clockBegin_shell3, clockEnd_shell3;
		clockBegin_shell3 = clock();
		ShellSort(h3, HUGE);
		clockEnd_shell3 = clock();
		cout<<"��"<<t+1<<"��ϣ����������ʱ��Ϊ"<<(clockEnd_shell3 - clockBegin_shell3)<<"ms"<<endl;
		total_h3 += (clockEnd_shell3 - clockBegin_shell3);

		clock_t  clockBegin_quick3, clockEnd_quick3;
		clockBegin_quick3 = clock();
		QuickSort(h4, 0, HUGE-1);
		clockEnd_quick3 = clock();
		cout<<"��"<<t+1<<"�ο�����������ʱ��Ϊ"<<(clockEnd_quick3 - clockBegin_quick3)<<"ms"<<endl;
		total_h4 += (clockEnd_quick3 - clockBegin_quick3);

		clock_t  clockBegin_bubble3, clockEnd_bubble3;
		clockBegin_bubble3 = clock();
		BubbleSort(h5, HUGE);
		clockEnd_bubble3 = clock();
		cout<<"��"<<t+1<<"��ð����������ʱ��Ϊ"<<(clockEnd_bubble3 - clockBegin_bubble3)<<"ms"<<endl;
		total_h5 += (clockEnd_bubble3 - clockBegin_bubble3);

		clock_t  clockBegin_bucket3, clockEnd_bucket3;
		clockBegin_bucket3 = clock();
		BucketSort(h6, HUGE);
		clockEnd_bucket3 = clock();
		cout<<"��"<<t+1<<"��Ͱ��������ʱ��Ϊ"<<(clockEnd_bucket3 - clockBegin_bucket3)<<"ms"<<endl;
		total_h6 += (clockEnd_bucket3 - clockBegin_bucket3);

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
	}

	cout<<"������СΪ1000ʱ���鲢����ƽ����ʱ"<<total_m1/times<<endl;
	cout<<"������СΪ1000ʱ����������ƽ����ʱ"<<total_m2/times<<endl;
	cout<<"������СΪ1000ʱ��ϣ������ƽ����ʱ"<<total_m3/times<<endl;
	cout<<"������СΪ1000ʱ����������ƽ����ʱ"<<total_m4/times<<endl;
	cout<<"������СΪ1000ʱ��ð������ƽ����ʱ"<<total_m5/times<<endl;
	cout<<"������СΪ1000ʱ��Ͱ����ƽ����ʱ"<<total_m6/times<<endl;

	cout<<"������СΪ10000ʱ���鲢����ƽ����ʱ"<<total_b1/times<<endl;
	cout<<"������СΪ10000ʱ����������ƽ����ʱ"<<total_b2/times<<endl;
	cout<<"������СΪ10000ʱ��ϣ������ƽ����ʱ"<<total_b3/times<<endl;
	cout<<"������СΪ10000ʱ����������ƽ����ʱ"<<total_b4/times<<endl;
	cout<<"������СΪ10000ʱ��ð������ƽ����ʱ"<<total_b5/times<<endl;
	cout<<"������СΪ10000ʱ��Ͱ����ƽ����ʱ"<<total_b6/times<<endl;

	cout<<"������СΪ100000ʱ���鲢����ƽ����ʱ"<<total_h1/times<<endl;
	cout<<"������СΪ100000ʱ����������ƽ����ʱ"<<total_h2/times<<endl;
	cout<<"������СΪ100000ʱ��ϣ������ƽ����ʱ"<<total_h3/times<<endl;
	cout<<"������СΪ100000ʱ����������ƽ����ʱ"<<total_h4/times<<endl;
	cout<<"������СΪ100000ʱ��ð������ƽ����ʱ"<<total_h5/times<<endl;
	cout<<"������СΪ100000ʱ��Ͱ����ƽ����ʱ"<<total_h6/times<<endl;

	delete []small_rand;
	delete []s1;
	delete []s2;
	delete []s3;
	delete []s4;
	delete []s5;
	delete []s6;

	return 0;
}