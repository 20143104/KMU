... 	// ���� ���� Ŭ���� ����
int main()
{
	Stack<char> s;  // ũ�Ⱑ 100�� ������ ����
	string str = "madamimadam";

	for(int i=0;i<str.length(); i++)
		s.push(str[i]);

	for(int i=0;i<str.length(); i++) {
		if( s.pop() != str[i] ) {
			cout << "�־��� ���ڿ��� ȸ���� �ƴ�" << endl;
			return 0;
		}
	}
	cout << "�־��� ���ڿ��� ȸ����" << endl;
	return 0;
}
