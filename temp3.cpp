#include<iostream>
using namespace std;

template<class T1,class T2>
void display(T1 x,T2 y)
{
	cout<<x<<endl<<y<<endl;
}

int main()
{
	display("anurag",2);
	display(5,6);
	return 0;
}
