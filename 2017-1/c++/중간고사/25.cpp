/******************************************************************************
*problem : 행렬곱셈                                           *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/


 #include<iostream>
 #include<fstream>


 using namespace std;

 int main(){
   ifstream instream;
   instream.open("input.txt");
   if(instream.fail()){
     cerr<<"input file opening failed\n";
   }
   int numtestcases;
   instream>>numtestcases;

   for(int i=0; i<numtestcases; i++){
     int r,s,t;
     instream>>r>>s>>t;

     int matrix1[r][s];
     int matrix2[s][t];
     int result[r][t];

     for(int k=0; k<r; k++){
       for(int l=0; l<s; l++){
          instream>>matrix1[k][l];
       }
     }


     for(int k=0; k<s; k++){
       for(int l=0; l<t; l++){
         instream>>matrix2[k][l];
       }
     }

     for(int k=0; k<r; k++){
       for(int l=0; l<t; l++){
         int sum=0;
         for(int p=0; p<s; p++)
            {sum+=matrix1[k][p]*matrix2[p][l];}
         result[k][l]= sum;
       }
     }

     for(int k=0; k<r; k++){
       for(int l=0; l<t; l++){
          cout<<result[k][l]<<" ";
        }
        cout<<endl;
      }
    }
   instream.close();
   return 0;
 }
