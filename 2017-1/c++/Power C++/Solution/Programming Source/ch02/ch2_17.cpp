#include <iostream>

using namespace std;

int main()
{
	int x = 0, y = 0, area = 0;

	

	cout<<"x��ǥ�� �Է��Ͻÿ�: ";
	cin>>x;
	cout<<"y��ǥ�� �Է��Ͻÿ�: ";
	cin>>y;
	
	(x>0 && y>0) ? (area=1): ((x<0 && y>0) ? (area=2) : ((x<0 && y<0) ? (area=3) : (area=4)));

	cout<<"��ǥ�� "<<area<<"��и��Դϴ�."<<endl;
	
		

	return 0;
}