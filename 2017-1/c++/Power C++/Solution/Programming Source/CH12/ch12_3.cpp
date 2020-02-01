#include <iostream>

using std::ostream;
using std::istream;
using std::endl;
using std::cout;
using std::cin;


class Date
{
	friend ostream& operator<<(ostream& os, const Date& c);
	int year;
	int month;
	int day;
public:
	Date()
	{
		year = 0;
		month = 0;
		day = 0;	
	}
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;	
	}
	~Date(){}
	Date operator++()
	{
		Date tmp;
		if( this->day <= 1){
			
			if(this->month <= 1){	
				tmp.year = this->year - 1 ;
				tmp.month = 12;
				tmp.day = 31;
			}
			else{
				tmp.year = this->year;
				tmp.month = this->month - 1;
				tmp.day = 31;
			}	
		}
		else{
			tmp.year = this->year;
			tmp.month = this->month;
			tmp.day = this->day-1;
		}

		return tmp;

	}
	Date operator--(){
		Date tmp;
		if( this->day >= 31){
			
			if(this->month >= 12){	
				tmp.year = this->year + 1;
				tmp.month = 1;
				tmp.day = 1;
			}
			else{
				tmp.year = this->year;
				tmp.month = this->month + 1;
				tmp.day = 1;
			}	
		}
		else{
			tmp.year = this->year;
			tmp.month = this->month;
			tmp.day = this->day+1;
		}
		return tmp;
	}
};

ostream& operator<<(ostream& os, const Date& c)
{
	os<<c.year<<"년"<<c.month<<"월"<<c.day<<"일"<<endl;
	return os;
}

int main()
{
	Date d(1987, 4, 27);
	cout<<d;
	cout<<"++ 연산자 : ";
	cout<<d++;
	cout<<"-- 연산자 : ";
	cout<<d--;

	return 0;
}
