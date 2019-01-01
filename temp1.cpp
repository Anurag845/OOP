#include<iostream>
using namespace std;

template<class T>
void maxi(T x,T y)
{
	if(x>y)
		cout<<x<<endl;
	else if(x<y)
		cout<<y<<endl;
	else
		cout<<"equal"<<endl;
}

int main()
{
	maxi(5,6);
	maxi(5.56,8.45);
	maxi(5,5);
	return 0;
}
