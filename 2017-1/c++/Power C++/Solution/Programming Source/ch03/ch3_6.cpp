#include <iostream>

using namespace std; 

int main()
{
	char c;
	scanf("%c", &c);
	//cin�� ��� ���鹮��, ���๮��, �ǹ��� �����ϱ� ������ ����� ������.
        
    switch (c)
	{
		case '\t':
			cout<<"�ǹ��� �Դϴ�.\n";
			break;
		case '\n':
			cout<<"�ٹٲ޹��� �Դϴ�.\n";
			break;
		case '\b':
			cout<<"�齺���̽� ���� �Դϴ�. \n";
            break;
     }
	return 0;
}

