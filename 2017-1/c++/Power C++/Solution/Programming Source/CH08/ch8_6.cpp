#include <iostream>
#include <string>

using namespace std;

int CheckGoods(string);

int main()
{
	string goodsN;

	cout<<"��ǰ��ȣ�� �Է��ϼ��� : ";
	cin>>goodsN;

	if(CheckGoods(goodsN) == 6)
		cout<<"�ùٸ� ��ǰ��ȣ�Դϴ�."<<endl;
	else
		cout<<"�ùٸ��� ���� ��ǰ ��ȣ �Դϴ�."<<endl;

	return 0;
}

int CheckGoods(string tmp)
{
	int i, j;
	int check = 0;
	if(tmp.length() == 6){
	
		for(int i=0; i < 6; i++){
			if( i == 0 || i == 1){
				if( (tmp[i] >= 'a' && tmp[i] <= 'z') || (tmp[i] >= 'A' && tmp[i] <= 'Z'))
					check++;
			}
			else{
				if( tmp[i] >= '1' && tmp[i] <= '9' )
					check++;

			}

		}
	}

	return check;
}