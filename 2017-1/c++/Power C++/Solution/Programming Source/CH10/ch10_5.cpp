#include <iostream>
#include <string>

using namespace std;

class SMS{
private:
	string transnum;
	string receptionnum;
	string msgtext;
	string time;
public:
	SMS(){}
	SMS(string tnum, string rnum)
	{
		transnum = tnum;
		receptionnum = rnum;
	}
	SMS(string tnum, string rnum, string m, string t)
	{
		transnum = tnum;
		receptionnum = rnum;
		msgtext = m;
		time = t;
	}
	void setTransnum(string tnum)
	{
		transnum = tnum;
	}
	void setReceptionnum(string rnum)
	{	
		receptionnum = rnum;
	}
	void setMsgtext(string m)
	{
		msgtext = m;
	}
	void setTime(string t)
	{
		time = t;
	}
	string getTransnum()
	{
		return transnum;
	}
	string getReceptionnum()
	{
		return receptionnum;
	}
	string getMsgtext()
	{
		return msgtext;
	}
	string getTime()
	{
		return time;
	}
	void print()
	{
		cout<<"송신자 : "<<transnum<<endl;
		cout<<"시  각 : "<<time<<endl;
		cout<<"메시지 : "<<msgtext<<endl;
	}

};


int main()
{
	SMS m1("010-555-2111","010-555-1111","Hi","03:10"), m2("010-555-1111","010-555-2111");
	m2.setTime("03:11");
	m2.setMsgtext("Hm..");
	m1.print();
	cout<<"============================"<<endl;
	m2.print();
	return 0;	
}
