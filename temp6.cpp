#include<iostream>
using namespace std;

template <class T1>
class Base
{
	T1 bdata;
   public:
   	void getdata()
   	{
   		cout<<"Enter base data"<<endl;
   		cin>>bdata;
   	}
   	void showdata()
   	{
   		cout<<"Base data is "<<bdata<<endl;
   	}
};

template <class T2>
class Derived : public Base<T2>
{
	T2 ddata;
   public:
   	void getData()
   	{
   		cout<<"Enter derived data "<<endl;
   		cin>>ddata;
   	}
   	void showData()
   	{
   		cout<<"Derived data is "<<ddata<<endl;
   	}
};

int main()
{
	Derived <float> obd;
	obd.getData();
	obd.showData();
	obd.getdata();
	obd.showdata();
	return 0;
}
