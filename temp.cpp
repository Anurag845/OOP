#include<iostream>
using namespace std;

template<class T>
T sum(T x,T y)
{
	return x+y;
}

int main()
{
	int c;
	c=sum(3,4);
	cout<<c<<endl;
	float e;
	e=sum(3.4,6.7);
	cout<<e<<endl;
	return 0;
}
