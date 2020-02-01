#include <iostream>

using namespace std;

class ProcessScore{
	double average;
public:
	ProcessScore(int *p, int index)
	{	
		int tmp=0;
		for(int i=0; i< index; i++)
		{
			if((*p) < 0) throw "IllegalScoreException";	
			tmp+= *p;
			p++;
		}
		average = tmp / 5.0;
	}
	void display()
	{
		cout<<"Æò±Õ Á¡¼ö´Â : "<<average<<endl;
	}
};
int main()
{
	int score[5]={10,20,-30,40,50};
	try{
		ProcessScore p(score, 5);
		p.display();
	}
	catch(char *e)
	{
		cout<<e<<endl;
	}	
	
	return 0;
}