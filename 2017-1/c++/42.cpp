/******************************************************************************
*problem : 숫자읽기                                       *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/
 #include<iostream>
 #include<fstream>
 #include<cmath>
 using namespace std;

 #define billion 1000000000
 #define million 1000000
 #define thousand 1000

void print(unsigned int &num){

  string one[11]={"","One_","Two_","Three_","Four_","Five_","Six_","Seven_","Eight_","Nine_"};
  string ten[11]={"Ten_","Eleven_","Twelve_","Thirteen_","Fourteen_","Fifteen_","Sixteen_","Seventeen_","Eighteen_","Nineteen_"};
  string ty[11]={"","","Twenty_","Thirty_","Forty_","Fifty_","Sixty_","Seventy_","Eighty_","Ninety_"};
  string str;
  if(num>=billion){
    str+=one[num/billion]+"Billion_";
    num%=billion;
  }
  if(num>=million){
    int data=num/million;
    if(data/100){
      str+=one[data/100]+"Hundred_";
      data%=100;
    }
    if(data/10==1){
      str+=ten[data%10];
    }
    else{
      if(data/10)
        str+=ty[data/10]+one[data%10];
      else
        str+=one[data%10];
    }
    str+="Million_";
    num%=million;
  }
  if(num>=thousand){
    int data=num/thousand;
    if(data/100){
      str+=one[data/100]+"Hundred_";
      data%=100;
    }
    if(data/10==1){
      str+=ten[data%10];
    }
    else{
      if(data/10)
        str+=ty[data/10]+one[data%10];
      else
        str+=one[data%10];
    }
    str+="Thousand_";
    num%=thousand;
  }
  if(num/100){
    str+=one[num/100]+"Hundred_";
    num%=100;
  }
  if(num/10==1){
    str+=ten[num%10];
  }
  else{
    if(num/10)
      str+=ty[num/10]+one[num%10];
    else
      str+=one[num%10];
  }

  int len=str.size();
  for(int i=0; i<len-1; i++)
    cout<<str[i];
}

int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail())
     cerr<<"input file opening failed.\n";

  int numtestcases;
  instream>>numtestcases;
  while(numtestcases--){
    unsigned int data;
    instream>>data;
    print(data);
    cout<<endl;

   }
   return 0;
 }
