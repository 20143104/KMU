#include <iostream>

using namespace std;

int main()
{
	char str[200], *pStr[50], *p;
	int i, j, cnt = 0, str_Cnt[50]={0};
	int n;

	cout<<"문자열을 입력하시오: ";
	cin.getline(str, 200);

	strlwr(str);

	p = str;
	n = strlen(str)-1;

	for(i=n; i >=0 ; i--){

		if( p[i] == ',' || p[i] == '.'){

			if(p[i+1] == ' ' || p[i+1] == NULL){
				for(j=i; j <= n ; j++)
					p[j] = p[j+1];	
			}
			else 
				p[i] = ' ';			
		}
	}

	j=0;
	if((pStr[cnt++] = strtok(str, " ")) ){
		while( (pStr[cnt++] = strtok(NULL, " "))){
			j++;
			for(i = 0; i < j ; i++){
					
				if( strcmp(pStr[j], pStr[i]) == 0){
					str_Cnt[i]++;
					cnt--;
					j--;
				}
			}
		}
	}
		
	cout<<"======================="<<endl;
	cout<<"단어            빈도"<<endl;
	cout<<"======================="<<endl;
	
	for(i=0; i< cnt-1; i++)
		cout<<pStr[i]<<"\t\t"<<str_Cnt[i]+1<<endl;

	return 0;
}
