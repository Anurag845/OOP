#include<iostream>
using namespace std;

class Calculator
{
	float a,b;
	public:
	char op;
	Calculator()
	{
		a=0;
		b=0;
		op='\0';
	}
	
	void getdata()
	{
		cout<<"Enter the 1st operand, operator and 2nd operand"<<endl;
		cin>>a;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter a float value"<<endl;
			cin>>a;
		}
		cin>>op;
		cin>>b;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter a float value"<<endl;
			cin>>b;
		}
	}
	
	void addition()
	{
		cout<<"Addition is "<<a+b<<endl;
	}
	
	void subtraction()
	{
		cout<<"Subtraction is "<<a-b<<endl;
	}
	
	void multiplication()
	{
		cout<<"Multiplication is "<<a*b<<endl;
	}
	
	void division()
	{
		cout<<"Division is "<<a/b<<endl;
	}
};

int main()
{
	Calculator C;
	char ch='y';
	while(ch=='y')
	{
		cout<<"Enter the data"<<endl;
		C.getdata();
		switch(C.op)
		{
		case '+':C.addition();
				 break;
		case '-':C.subtraction();
				 break;
		case '*':C.multiplication();
				 break;			
		case '/':C.division();
				 break;
		default: cout<<"Incorrect option"<<endl;		
		}
		cout<<"Do you want to continue?"<<endl;
		cin>>ch;
	}
	return 0;
}
