#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string sWord, sNum, sBeg, sSym;
int iPos;

int main()
{
do
 {
  iPos=0; sWord=""; sNum="";
  cin>>sBeg;
  for(int i=0; i<sBeg.length(); i++)
   {
    sSym=sBeg[iPos];
    if(sSym>="0" && sSym<="9") sNum=sNum+sBeg[iPos];
    else
     {
      if(sNum=="") sNum="1";
      for(int j=atoi(sNum.c_str()); j!=0; j--) sWord=sWord+sBeg[iPos];
      sNum="";
     }
    iPos++;
   } 
  cout<<endl<<endl;
  int z=0;
  ofstream file("file.txt");
  for(int i=0; i!=sWord.length(); i++) 
   {
    if(z!=39) file<<sWord[i];
    else 
     {
      z=0;
      file<<sWord[i]<<"\n";
     }
    z++; 
   } 
 }
while(true);
}
