#include<iostream>
#include<stack>
using namespace std;

stack<int> read()
{
	stack<int> s;
    int x,n,i;
    cout<<"Enter the number of bits in the binary number"<<endl;
    cin>>n;
    while(!cin)
    {
    	cin.clear();
    	cin.ignore(5,'\n');
    	cout<<"Enter only integer value"<<endl;
    	cin>>n;
    }
    cout<<"Enter the binary number"<<endl;
    for(i=0;i<n;i++)
    {
    	cin>>x;
    	while(x!=0 && x!=1)
    	{
    		cin.clear();
    		cin.ignore(5,'\n');
    		cout<<"Enter either 0 or 1"<<endl;
    		cin>>x;
    	}
    	s.push(x);
    }
    return s;
}
 
void display(stack<int> &s)
{
    while(!s.empty())
    {
    	cout<<s.top()<<" ";
    	s.pop();
    }
    cout<<endl;
}
        
stack<int> add(stack<int> &s1,stack<int> &s2)
{
    stack<int> s;
    int sum,carry=0,b1,b2;
    while(!s1.empty()||!s2.empty())
    {
    	b1=b2=0;
    	if(!s1.empty())
        {
        	b1=s1.top();
      		s1.pop();
    	}
    	if(!s2.empty())
      	{
        	b2=s2.top();
        	s2.pop(); 
      	}
    	sum=(b1+b2+carry)%2;
    	carry=(b1+b2+carry)/2;
    	s.push(sum);
    }
    if(carry==1)
    	s.push(1);
    return s;
  }
 
int main()
{
    stack<int> s1,s2,s3;
    int ch;
    char c='y';
    while(c=='y')
    {
    	cout<<"Press 1 to enter first binary number"<<endl;
    	cout<<"Press 2 to enter second binary number"<<endl;
    	cout<<"Press 3 to perform addition of two binary numbers"<<endl;
 		cin>>ch;
 		while(!cin)
 		{
 			cin.clear();
 			cin.ignore(5,'\n');
 			cout<<"Enter a value from 1 to 3"<<endl;
 			cin>>ch;
 		}
 		switch(ch)
      	{
        	case 1: s1=read();
           			break;
 			case 2: s2=read();
           			break;
 	        case 3: cout<<"The result of addition is"<<endl;
           			s3=add(s1,s2);
           			display(s3);
           			break;
           	default:cout<<"Invalid choice"<<endl;
           			break;
      	}
      	cout<<"Do you want to continue? (y/n)"<<endl;
      	cin>>c;
    }
    return 0;
  }
