#include <iostream>

using namespace std;

int main()
{
  int target;
  cin>>target;
  for(int i=1;i<=target;i++)
  {
    for(int j=1;j<=i;j++)
    {
      cout<<"*";
    }
    cout<<endl;
  }
}