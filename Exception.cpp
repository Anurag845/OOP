#include<iostream>
using namespace std;

class UserInfo
{
	int age;
	float income;
	string place;
	bool vehicle;
	public:
	UserInfo()
	{
		age=18;
		income=50000.0;
		place="Pune";
		vehicle=true;
	}
	
	void getdata()
	{
		cout<<"Enter age ";
		cin>>age;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter an integer value"<<endl;
			cin>>age;
		}
		cout<<"Enter income ";
		cin>>income;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter a float value"<<endl;
			cin>>income;
		}
		cout<<"Enter place ";
		cin>>place;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter an string value"<<endl;
			cin>>place;
		}
		cout<<"Enter 1 if you have a 4 wheeler. Otherwise enter 0 ";
		cin>>vehicle;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter a boolean value"<<endl;
			cin>>vehicle;
		}
		try
		{
			if(age<18 || age>55)
				throw age;
			if(income<50000 || income>100000)
				throw income;
			if(place!="Pune" && place!="Mumbai" && place!="Bangalore" && place!="Chennai") 
				throw place;
			if(vehicle!=true)
				throw vehicle;
		}
		catch(int a)
		{
			cout<<a<<" is not between 18 and 55"<<endl;
		}
		catch(float i)
		{
			cout<<i<<" is not between 50000 and 100000"<<endl;
		}
		catch(string p)
		{
			cout<<p<<" is not one of the metro cities"<<endl;
		}
		catch(bool v)
		{
			cout<<"You do not own a 4 wheeler"<<endl;
		}
	}
};

int main()
{
	UserInfo U;
	U.getdata();
	return 0;
}
