/******************************************************************************
*problem : 숫자의 진법변환                                        *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/
 #include<iostream>
 #include<fstream>
 #include<string>
 #include<cmath>

 using namespace std;
 void change(string &num,int n,int m,char base[]);
 void change_2(unsigned long data,int n,int m,char base[]);
 int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail()){
    cerr<<"input file opening failed.\n";
  }
  int numtestcases;
  instream>>numtestcases;
  while(numtestcases--){
  char base[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
  int s,t;
  instream>>s;
  if(s==10){
    unsigned long data;
    instream>>data>>t;
    change_2(data,s,t,base);
  }
  else{
    string array;
    instream>>array>>t;
    change(array,s,t,base);
  }
  }
  return 0;
  instream.close();
  }
  void change(string &num,int n,int m,char base[]){
    int size=num.length();
    unsigned long sum=0;
    for(int i=0; i<size; i++){
      for(int k=0; k<16; k++){
        if(num[i]==base[k])
          {sum+=k*pow(n,size-1-i);}
      }
    }  ////10진법으로 변환

    if(m==10)
    {cout<<sum<<endl;}
    else{
      int final[32]={0,};
      int i=0;
      for(; sum!=0; i++)
      {
        final[i]=sum%m;
        sum/=m;
      }
      for(int k=i-1; k>=0; k--){
        for(int l=0; l<16; l++){
          if(final[k]==l)
            {cout<<base[l];}
        }
      }
      cout<<endl;
    }
  }
  void change_2(unsigned long data,int n,int m,char base[]){
    int final[32]={0,};
    int i=0;
    for(; data!=0; i++)
    {
      final[i]=data%m;
      data/=m;
    }
    for(int k=i-1; k>=0; k--){
      for(int l=0; l<16; l++){
        if(final[k]==l)
          {cout<<base[l];}
      }
    }
    cout<<endl;
  }
