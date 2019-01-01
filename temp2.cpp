#include<iostream>
using namespace std;

template<class T>
void interchange(T &x,T &y)
{
	T temp;
	temp=x;
	x=y;
	y=temp;
}

int main()
{
	int a,b;
	cout<<"Enter 2 integers"<<endl;
	cin>>a>>b;
	interchange(a,b);
	cout<<"After swapping "<<endl<<a<<endl<<b<<endl;
	float c,d;
	cout<<"Enter 2 floats"<<endl;
	cin>>c>>d;
	interchange(c,d);
	cout<<"After swapping "<<endl<<c<<endl<<d<<endl;
}
