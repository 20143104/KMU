#include <iostream>
#include <vector>		// ���͸� ����Ϸ��� �� ��� ������ �����Ͽ��� �Ѵ�
using namespace std;

int main()
{
	vector<double> scores;	// ���͸� �����Ѵ�. 

	while(true)
	{
		double value = 0.0;
		cout << "������ �Է��Ͻÿ�(����� -1): ";
		cin >> value;
		if( value < 0.0 ) break;
		scores.push_back(value);
	}

	double highest = -100;
	vector<double>::iterator it;
	for(it = scores.begin(); it < scores.end() ; it++)
		if( *it > highest )
			highest = *it;


	cout << "�ְ� ������ " << highest << "�Դϴ�.\n";

	return 0;
}
