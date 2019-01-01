#include<iostream>
using namespace std;

template<class T1,class T2>
class person
{
	T1 age;
	T2 name;
  public:
	void getdata()
	{
		cout<<"Enter age and name"<<endl;
		cin>>age>>name;
	}
	void showdata()
	{
		cout<<"Entered age is "<<age<<endl;
		cout<<"Entered name is "<<name<<endl;
	}
};

int main()
{
	person <int,string>ob1;
	ob1.getdata();
	ob1.showdata();
	person <float,char[40]>ob2;
	ob2.getdata();
	ob2.showdata();
	return 0;
}
