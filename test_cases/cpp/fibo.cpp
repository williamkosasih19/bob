#include <iostream>

using namespace std;

int rec(int index)
{
   if(index<=1)
      return 1;
   return rec(index-1)+rec(index-2);
}

int main()
{
  int a;
  cin>>a;
  cout<<rec(a)<<endl;
}