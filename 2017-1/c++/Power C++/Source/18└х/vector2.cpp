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

	double highest = scores[0];
	for(int i = 1; i < scores.size() ; i++)
		if( scores[i] > highest )
			highest = scores[i];
	cout << "�ְ� ������ " << highest << "�Դϴ�.\n";

	return 0;
}
