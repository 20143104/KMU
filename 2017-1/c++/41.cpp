/******************************************************************************
*problem : 신용카드                                       *
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


 int iscard(string data){
   int len = data.size();
   int array[20]={0,};
   int sum=0;
   int x=0;

   for(int i=0; i<len; i++){
     array[i]=data[i]-48;
   }

   if(data[0]=='3'){
     if(!(len==15 || len==14))
      return 0;
    }
   else if(data[0]=='6'){
     if(!(len==16))
      return 0;
   }
   else if(data[0]=='5'){
     if(!(len==16))
      return 0;
   }
   else if(data[0]=='4'){
     if(!(len==13 || len==16))
      return 0;
   }
   else
      return 0;


  for(int i=len-2; i>=0; i-=2){
    array[i]*=2;
    if(array[i]>=10)
      array[i]-=9;
  }


  for(int i=0; i<len-1; i++)
    sum+=array[i];

  for( ; x<10; x++){
    if(((sum+x)%10)==0)
      break;
  }

  if(x==array[len-1])
    return 1;
  else
     return 0;
 }
 int main(){
   ifstream instream;
   instream.open("input.txt");
   if(instream.fail())
     cerr<<"input file opening failed.\n";

   int numtestcases;
   instream>>numtestcases;
   while(numtestcases--){
     string data;
     instream>>data;
     cout<<iscard(data)<<endl;
   }
   return 0;
 }
