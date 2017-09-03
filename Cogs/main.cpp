#include <iostream>

int iA, iB, iAm, iBm, iN;

using namespace std;

int main()
{
do
 {
  iA=1; iB=1; iN=0;    
  cin>>iAm>>iBm;
  while(true)
   {
    iA++; iB++; iN++;
    if(iA>iAm) iA=1;
    if(iB>iBm) iB=1;
    if(iA==1 && iB==1) break;
   }
  cout<<iN<<endl<<endl;
 }
while(true);
}
