#include <iostream>

using namespace std;

int main()
{
	int feet = 0; 
	
	double inch = 0, height = 0, Dfeet = 0;
	

	cout<<"Ű�� �Է��Ͻÿ�.(��Ʈ):";
	cin>>feet;
	cout<<"Ű�� �Է��Ͻÿ�.(��ġ):";
	cin>>inch;

	height = (inch + feet*12)*2.54;

	cout<<feet<<"��Ʈ "<<inch<<"��ġ�� "<<height<<" cm�Դϴ�."<<endl;
	

	return 0;
}