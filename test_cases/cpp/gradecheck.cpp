#include <iostream>

using namespace std;

int main()
{
  int grade;
  cout<<"please enter your grade"<<endl;
  cin>>grade;
  cout<<"Grade : ";
  if(grade>100)
     cout<<"invalid!"<<endl;
  else if(grade>84)
     cout<<"A"<<endl;
  else if(grade>69)
     cout<<"B"<<endl;
  else if(grade>49)
     cout<<"C"<<endl;
  else if(grade>24)
     cout<<"D"<<endl;
  else if(grade>=0)
     cout<<"F"<<endl;
  else
     cout<<"invalid!"<<endl;
}