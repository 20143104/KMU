#include <iostream>
#define SIZE 100

using namespace std;

void ChangeText(char *str, int size);

int main()
{
	char input[SIZE];

	cin.getline(input, SIZE);
	cout<<" 입력문 : "<<input<<endl;
	ChangeText(input, SIZE);
	cout<<" 변경문 : "<<input<<endl;

}
void ChangeText(char *str, int size)
{
	int i;

	if(str[0] >= 'a' && str[0] <= 'z')
		str[0] =  str[0] - 32;

	for(i=0; i<size;i++){
		if(str[i] == NULL){
			if(str[i-1] != '.'){
				str[i] = '.';
				str[i+1] = NULL;
			}
			break;
		}
	}
	
}