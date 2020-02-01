#include <iostream>
#define MAX_STU 10

using namespace std;

typedef struct Student{
	int num;
	int test1;
	int test2;
	int test3;
	int h_s;
	int l_s;
	int sum;
	double ave;
}STUDENT;

int MODE(int data[], int n);
void bubble_sort(STUDENT *std, int n);
void bubble_sort(int *a, int n);

int main()
{
	int i;
	int tmp=0;
	int mid1[MAX_STU]={0}, mid2[MAX_STU]={0}, mid3[MAX_STU]={0};
	int mode1 = 0, mode2 = 0, mode3 = 0;
	double h_s[3]={0}, l_s[3]={0}, sum[3]={0}, ave[3]={0};
	int stu_count = 0;
	STUDENT std[MAX_STU];

	cout<<"학생 수를 입력하세요 : ";
	cin>>stu_count;

	for(i=0; i < stu_count; i++)
	{
		cout<<"학번 시험#1 시험#2 시험#3 (ex 1 30 10 11) : ";
		cin>>std[i].num>>std[i].test1>>std[i].test2>>std[i].test3;

		sum[0] = sum[0] + std[i].test1;
		sum[1] = sum[1] + std[i].test2;
		sum[2] = sum[2] + std[i].test3;

		mid1[i] = std[i].test1;
		mid2[i] = std[i].test2;
		mid3[i] = std[i].test3;

		std[i].sum = (std[i].test1 + std[i].test2 + std[i].test3);
		std[i].ave = std[i].sum / 3;

		if(std[i].test1 > std[i].test2){

			if( std[i].test1 > std[i].test3 ){
				std[i].h_s = std[i].test1;
				if( std[i].test2 > std[i].test3 )
						std[i].l_s = std[i].test3;
					else 
						std[i].l_s = std[i].test2;
				}
				else{
					std[i].h_s = std[i].test3;
					if( std[i].test1 > std[i].test2 )
						std[i].l_s = std[i].test2;
					else 
						std[i].l_s = std[i].test1;
				}
			}
			else{
				if( std[i].test2 > std[i].test3 ){
					std[i].h_s = std[i].test2;
					if( std[i].test1 > std[i].test3 )
						std[i].l_s = std[i].test3;
					else 
						std[i].l_s = std[i].test1;
				}
				else{
					std[i].h_s = std[i].test3; // test2 <test3
				if( std[i].test1 > std[i].test2 )
					std[i].l_s = std[i].test2;
				else 
					std[i].l_s = std[i].test1;
			}
			
		}

	}

	mode1 = MODE(mid1, stu_count);
	mode2 = MODE(mid2, stu_count);
	mode3 = MODE(mid3, stu_count);


	bubble_sort(mid1, stu_count);
	bubble_sort(mid2, stu_count);
	bubble_sort(mid3, stu_count);

	h_s[0] = std[0].test1;
	h_s[1] = std[0].test2;
	h_s[2] = std[0].test3;
	l_s[0] = std[0].test1;
	l_s[1] = std[0].test2;
	l_s[2] = std[0].test3;

	for(i=1; i< stu_count; i++){
		if(h_s[0] < std[i].test1)
			h_s[0] = std[i].test1;
		if(h_s[1] < std[i].test2)
			h_s[1] = std[i].test2;
		if(h_s[2] < std[i].test3)
			h_s[2] = std[i].test3;
		if(l_s[0] > std[i].test1)
			l_s[0] = std[i].test1;
		if(l_s[1] > std[i].test2)
			l_s[1] = std[i].test2;
		if(l_s[2] > std[i].test3)
			l_s[2] = std[i].test3;
	}

	ave[0] = sum[0] / stu_count;
	ave[1] = sum[1] / stu_count;
	ave[2] = sum[2] / stu_count;


	cout<<endl<<endl;
	cout<<" + 학생 성적 +"<<endl;
	cout<<"-------------------------------------------------------------"<<endl;
	cout<<" 학번 시험#1  시험#2  시험#3   최고    최저    평균    총점"<<endl;
	cout<<"-------------------------------------------------------------"<<endl;

	for(i=0; i < stu_count; i++)
	{
		cout<<"   "<<std[i].num<<"\t"<<std[i].test1<<"\t"<<std[i].test2<<"\t"<<std[i].test3<<"\t"<<std[i].h_s<<"\t"<<std[i].l_s<<"\t"<<std[i].ave<<"\t"<<std[i].sum<<endl;
	}

	cout<<"-------------------------------------------------------------"<<endl;
	cout<<" 시험#1 최대 점수 : "<<h_s[0]<<", 최저 점수 : "<<l_s[0]<<", 평균 점수 : "<<ave[0]<<endl;
	cout<<" 시험#2 최대 점수 : "<<h_s[1]<<", 최저 점수 : "<<l_s[1]<<", 평균 점수 : "<<ave[1]<<endl;
	cout<<" 시험#3 최대 점수 : "<<h_s[2]<<", 최저 점수 : "<<l_s[2]<<", 평균 점수 : "<<ave[2]<<endl;
	cout<<"-------------------------------------------------------------"<<endl;

	cout<<"-------------------------------------------------------------"<<endl;
	cout<<" 시험#1 산술 평균 : "<<ave[0]<<", 중간값 : "<<mid1[stu_count/2]<<", 모드값(최빈값) : "<<mode1<<endl;
	cout<<" 시험#2 산술 평균 : "<<ave[1]<<", 중간값 : "<<mid2[stu_count/2]<<", 모드값(최빈값) : "<<mode2<<endl;
	cout<<" 시험#3 산술 평균 : "<<ave[2]<<", 중간값 : "<<mid3[stu_count/2]<<", 모드값(최빈값) : "<<mode3<<endl;
	cout<<"-------------------------------------------------------------"<<endl<<endl;;
	cout<<" + 학생 성적(총점 석차순) +"<<endl;
	cout<<"-------------------------------------------------------------"<<endl;
	cout<<" 학번 시험#1  시험#2  시험#3   최고    최저    평균    총점"<<endl;
	cout<<"-------------------------------------------------------------"<<endl;


	bubble_sort(std, stu_count);
	
	for(i=0; i < stu_count; i++)
	{
		cout<<"   "<<std[i].num<<"\t"<<std[i].test1<<"\t"<<std[i].test2<<"\t"<<std[i].test3<<"\t"<<std[i].h_s<<"\t"<<std[i].l_s<<"\t"<<std[i].ave<<"\t"<<std[i].sum<<endl;
	}



	return 0;
}

void bubble_sort(int *a, int n)
{
	int temp;
	int i, j;

	for(i=0; i < n-1 ; i++){
		for(j=0; j < n-i-1; j++){
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

}

void bubble_sort(STUDENT *std, int n)
{
	STUDENT temp;
	int i, j;

	for(i=0; i < n-1 ; i++){
		for(j=0; j < n-i-1; j++){
			if(std[j].sum > std[j+1].sum)
			{
				temp = std[j];
				std[j] = std[j+1];
				std[j+1] = temp;
			}
		}
	}

}

int MODE(int data[], int n)
{
	int i, j;
	int count;
	int Max_C = 0;
	int Max_I = 0;
	
	for(i=0; i< n; i++){
		count = 0;
		for(j=0; j< n; j++)
		{
			if(data[i] == data[j])
				count++;
		}
		if(count > Max_C)
		{
			Max_C = count;
			Max_I = i;
		}
		if(count > n / 2)
			break;
	}
	return data[Max_I];
}
