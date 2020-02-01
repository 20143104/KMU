#include <iostream>
#include <string>
using namespace std;

int main()
{
	string prob = ��space";
	int length = prob.length();
	int tries=0;
	string answer(length, '-');	// -�� �ʱ�ȭ

	cout << "���� ����: " << answer << endl;
	while(tries < 6 && answer != prob ){
		char c;
		cout << "���ڸ� �����Ͻÿ�: ";
		cin >> c;
		if( answer.find(c) != string::npos ){
			cout << "���� ������ �����Դϴ�. ";
			continue;
		}
		int pos = prob.find(c);
		if( pos == string::npos ){
			cout << "������ ���ڰ� �����ϴ�." << endl;
			tries++;
			continue;
		}
		else{
			answer[pos] = c;
			pos = prob.find(c, pos+1);	// ���� ���ڰ� �� ������ �ݺ������� ã�´�.
			while(pos != string::npos){
				answer[pos] = c;
				pos = prob.find(c, pos+1);
			}
		}
		cout << "���� ����: " << answer << endl;
		if( answer == prob ) {
			cout << "�¾ҽ��ϴ�" << endl;
			break;
		}
	}
	if( tries >= 6 ){
		cout << "Ʋ�Ƚ��ϴ�. ������ " << prob << "�Դϴ�." << endl;
	}
	return 0;
}	
