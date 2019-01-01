#include<iostream>
using namespace std;
#include<math.h>

class Quadratic
{
	float a,b,c;
	public:
	Quadratic()
	{
		a=0;
		b=0;
		c=0;
	}
	
	void operator >> (istream &in)
	{
		cout<<"Enter values of coefficients of x^2, x and constant term"<<endl;
		in>>a>>b>>c;
	}
	
	void operator << (ostream &out)
	{
		out<<a<<"x^2 + "<<b<<"x + "<<c<<" = 0"<<endl;
	}
	
	Quadratic operator + (Quadratic &q)
	{
		Quadratic sum;
		sum.a=a+q.a;
		sum.b=b+q.b;
		sum.c=c+q.c;
		return sum;
	}
	
	void evaluate()
	{
		float ans,x;
		cout<<"Enter the value of x"<<endl;
		cin>>x;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter only float value"<<endl;
			cin>>x;
		}
		ans=a*x*x+b*x+c;
		cout<<"Answer is "ans<<endl;
	}
	
	void roots()
	{
		float x1,x2,D;
		D=b*b-4*a*c;
		if(D==0)
		{
			x1=(-b)/(2*a);
			x2=x1;
			cout<<"Roots are real and equal"<<endl;
			cout<<"x1 = x2 = "<<x1;
		}
		else if(D>0)
		{
			x1=(-b+sqrt(D))/(2*a);
			x2=(-b-sqrt(D))/(2*a);
			cout<<"Roots are real and distinct"<<endl;
			cout<<"x1 = "<<x1<<endl;
			cout<<"x2 = "<<x2<<endl;
		}
		else 
		{
			cout<<"Roots are imaginary"<<endl;
		}
	}
};

int main()
{
	Quadratic q1,q2,q3;
	char c='y';
	int choice1,choice2;
	while(c=='y')
	{
		cout<<"Press 1 to enter a quadratic equation"<<endl;
		cout<<"Press 2 to add two quadratic equations"<<endl;
		cout<<"Press 3 to evaluate the equation for a value of x"<<endl;
		cout<<"Press 4 to find the roots of an equation"<<endl;
		cin>>choice1;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter a value from 1 to 4"<<endl;
			cin>>choice1;
		}
		switch(choice1)
		{
			case 1: cout<<"Press 1 to enter 1st equation"<<endl;
					cout<<"Press 2 to enter 2nd equation"<<endl;
					cin>>choice2;
					while(!cin)
					{
						cin.clear();
						cin.ignore(5,'\n');
						cout<<"Enter 1 or 2"<<endl;
						cin>>choice2;
					}
					if(choice2==1)
					{
						q1>>cin;
						q1<<cout;
					}
					else if(choice2==2)
					{
						q2>>cin;
						q2<<cout;
					}
					else 
					{	
						cout<<"Invalid choice"<<endl;
					}
					break;
			case 2: q3=q1+q2;
					q3<<cout;
					break;
			case 3: cout<<"Press 1 to evaluate for 1st equation"<<endl;
					cout<<"Press 2 to evaluate for 2nd equation"<<endl;
					cout<<"Press 3 to evaluate for 3rd equation"<<endl;
					cin>>choice2;
					while(!cin)
					{
						cin.clear();
						cin.ignore(5,'\n');
						cout<<"Enter a value from 1, 2 and 3"<<endl;
						cin>>choice2;
					}
					if(choice2==1)
					{
						q1.evaluate();
					}
					else if(choice2==2)
					{
						q2.evaluate();
					}
					else if(choice2==3)
					{	
						q3.evaluate();
					}
					else
					{
						cout<<"Invalid choice"<<endl;
					}
					break;
			case 4: cout<<"Press 1 to evaluate for 1st equation"<<endl;
					cout<<"Press 2 to evaluate for 2nd equation"<<endl;
					cout<<"Press 3 to evaluate for 3rd equation"<<endl;
					cin>>choice2;
					while(!cin)
					{
						cin.clear();
						cin.ignore(5,'\n');
						cout<<"Enter a value from 1, 2 and 3"<<endl;
						cin>>choice2;
					}
					if(choice2==1)
					{
						q1.roots();
					}
					else if(choice2==2)
					{
						q2.roots();
					}
					else if(choice2==3)
					{	
						q3.roots();
					}
					else
					{
						cout<<"Invalid choice"<<endl;
					}
					break;
		}
		cout<<"Do you want to continue? (y/n)"<<endl;
		cin>>c;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter y or n"<<endl;
			cin>>c;
		}
	}
	return 0;
}
