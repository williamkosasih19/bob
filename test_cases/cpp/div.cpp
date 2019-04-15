#include <iostream>

using namespace std;

int rec(int a, int b)
{
	if(b>a)
		return rec(b,a);
	if(b==0)
		return a;
	return rec(b,a%b);
}


int main()
{
	int a,b;
	cout<<"a?"<<endl;
	cin>>a;
	cout<<"b?"<<endl;
	cin>>b;
	cout<<"gcd="<<rec(a,b)<<endl;
}