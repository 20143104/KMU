class String {
	char *s;
public:
	String(char *p){
		s = new char[strlen(p)+1];
		strcpy(s, p);
	}
	virtual ~String(){
		cout << "String() �Ҹ���" << endl;
		delete[] s;
	}
};
class MyString : public String {
	...// �հ� ����
};

int main()
{
	...// �հ� ����
}
