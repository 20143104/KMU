#include <iostream>
#include <vector>		// ���͸� ����Ϸ��� �� ��� ������ �����Ͽ��� �Ѵ�
using namespace std;

int main()
{
	vector<double> scores(10);	// ���͸� �����Ѵ�. 

	for(int i = 0; i < scores.size() ; i++)
	{
		cout << "������ �Է��Ͻÿ�: ";
		cin >> scores[i];	
	}

	double highest = scores[0];
	for(int i = 1; i < scores.size() ; i++)
		if( scores[i] > highest )
			highest = scores[i];
	cout << "�ְ� ������ " << highest << "�Դϴ�.\n";

	return 0;
}
