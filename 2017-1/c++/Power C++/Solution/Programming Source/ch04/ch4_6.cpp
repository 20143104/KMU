#include <iostream>

using namespace std;

int cal_parking_charge(int time);

int main()
{
	int time = 0;

	cout<<"�����ð��� �Է��Ͻÿ�: ";
	cin>>time;

	cout<<"��������� "<<cal_parking_charge(time)<<"�� �Դϴ�."<<endl;

	return 0;
}

int cal_parking_charge(int time)
{
	if(time <= 2){
		return 3000;
	}
	else{
		if(3000 + 2000*(time-2) > 6000){
			return 6000;
		}
		else{
			return 3000 + 2000*(time-2);
		}
	}

}