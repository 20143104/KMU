#include <iostream>

using namespace std;

int main()
{
	int feet = 0; 
	
	double inch = 0, height = 0, Dfeet = 0;
	

	cout<<"Ű�� �Է��Ͻÿ�.:";
	cin>>height;

	feet = height/30.48;
	Dfeet = height/30.48;
	inch = (Dfeet - feet)*12;

	cout<<height<<"cm�� "<<feet<<"��Ʈ "<<inch<<" ��ġ�Դϴ�."<<endl;
	

	return 0;
}