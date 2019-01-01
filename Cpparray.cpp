#include<iostream>
using namespace std;

class CppArray
{
	int *p,size;
	public:
	CppArray()
	{
		p=NULL;
	}
	
	void operator >> (istream &in)
	{
		int i;
		cout<<"Enter the number of elements in the array"<<endl;
		cin>>size;
		p=new int[size];
		cout<<"Enter the elements"<<endl;
		for(i=0;i<size;i++)
		{
			in>>p[i];
		}
	}
	
	void operator << (ostream &out)
	{
		out<<"Elements are "<<endl;
		for(int i=0;i<size;i++)
		{
			out<<p[i]<<" ";
		}
		out<<endl;
	}
	
	void operator [] (int i)
	{
		if(i>=size)
		{
			cout<<"Array out of bounds"<<endl;
		}
		else
		{
			cout<<"Requested element is "<<p[i]<<endl;
		}
	}
	
	int sizearr()
	{
		return sizeof(int)*size;
	}
	
	void operator = (CppArray c)
	{
		size=c.size;
		p=new int[size];
		for(int i=0;i<size;i++)
		{
			p[i]=c.p[i];
		}
	}
};

int main()
{
	CppArray cp1,cp2;
	int ch1,index,size_arr;
	char c='y';
	while(c=='y')
	{
		cout<<"Press 1 to enter elements of array"<<endl;
		cout<<"Press 2 to equate one array to another"<<endl;
		cout<<"Press 3 to perform range checking"<<endl;
		cout<<"Press 4 to get the size of array"<<endl;
		cin>>ch1;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter a value from 1 to 4"<<endl;
			cin>>ch1;
		}
		switch(ch1)
		{
			case 1: cp1>>cin;
					cp1<<cout;
					break;
			case 2: cp2=cp1;
					cout<<"After copying, ";
					cp2<<cout;
					break;
			case 3: cout<<"Enter the index of element"<<endl;
					cin>>index;
					cp1[index];
					break;
			case 4: size_arr=cp1.sizearr();
					cout<<"Size of array is "<<size_arr<<endl;
					break;
			default:cout<<"Invalid choice"<<endl;
					break;
		}
		cout<<"Do you want to continue? (y/n)"<<endl;
		cin>>c;
	}
	return 0;
}
