#include<iostream>
using namespace std;

template<class T>
class Person
{
	T age;
   public:
   	
   	Person()
   	{
   		age=20;
   	}
   	
   	Person(T a)
   	{
   		age=a;
   	}
   	
	void getdata();
	
	void showdata();
};

template <class T> void Person<T> :: getdata()
{
	cout<<"Enter age"<<endl;
	cin>>age;
}

template <class T> void Person<T> :: showdata()
{
	cout<<"Age is "<<age<<endl;
}

int main()
{
	Person <int> ob1(25);
	ob1.showdata();
	Person <float> ob2(24.56);
	ob2.showdata();
	ob1.getdata();
	ob1.showdata();
	return 0;
}
