#include<iostream>
using namespace std;

class Complex
{
	float real,imaginary;
	public:
	Complex()
	{
		real=0;
		imaginary=0;
	}
	
	Complex(float a,float b)
	{
		real=a;
		imaginary=b;
	}
	
	void operator >> (istream &in)
	{
		cout<<"Enter the real part- ";
		in>>real;
		while(!in)
		{	
			in.clear();
			in.ignore(5,'\n');
			cout<<"Enter only float value"<<endl;
			in>>real;
		}
		cout<<"Enter the imaginary part- ";
		in>>imaginary;
		while(!in)
		{
			in.clear();
			in.ignore(5,'\n');
			cout<<"Enter only float values"<<endl;
			in>>imaginary;
		}
	}
	
	void operator << (ostream &out)
	{
		out<<real<<"+"<<imaginary<<"i"<<endl;
	}
	
	Complex operator + (Complex c)
	{
		Complex res;
		res.real=real+c.real;
		res.imaginary=imaginary+c.imaginary;
		return res;
	}
	
	Complex operator * (Complex c)
	{
		Complex res;
		res.real=real*c.real-imaginary*c.imaginary;
		res.imaginary=imaginary*c.real+real*c.imaginary;
		return res;
	}
};

int main()
{
	Complex c1,c2,c3,c4;
	char ch='y';
	int choice,choice2;
	while(ch=='y' || ch=='Y')
	{
		cout<<"Press 1 to enter a complex number"<<endl;
		cout<<"Press 2 to add two complex numbers"<<endl;
		cout<<"Press 3 to multiply two complex numbers"<<endl;
		cin>>choice;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter a choice between 1 and 4"<<endl;
			cin>>choice;
		}
		switch(choice)
		{
			case 1: cout<<"Press 1 to enter 1st complex number"<<endl;
					cout<<"Press 2 to enter 2nd complex number"<<endl;
					cin>>choice2;
					while(!cin)
					{
						cin.clear();
						cin.ignore(5,'\n');
						cout<<"Enter a choice between 1 and 2"<<endl;
						cin>>choice2;
					}
					if(choice2==1)
					{
						c1>>cin;
				    	cout<<"Entered complex number is ";
				    	c1<<cout;
					}
					else if(choice2==2)
					{
						c2>>cin;
				    	cout<<"Entered complex number is ";
				    	c2<<cout;
					}
					break;
			case 2: c3=c1+c2;
					cout<<"Addition is ";
					c3<<cout;
					break;
			case 3: c4=c1*c2;
					cout<<"Multiplication is ";
					c4<<cout;
					break; 
			default:cout<<"Enter a choice from 1, 2 and 3"<<endl;
					break;
		}
		cout<<"Do you want to continue? (y/n)"<<endl;
		cin>>ch;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter either y or n"<<endl;
			cin>>ch;
		}
	}
	return 0;
}
