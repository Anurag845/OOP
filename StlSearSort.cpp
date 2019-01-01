/*#include<iostream>
#include<list>
#include<string>
using namespace std;

class Person
{
	string fname;
	string lname;
	string telno;
	string dob;
	public:
	Person()
	{
		fname=lname=telno=dob="";
	}
	
	void accept()
	{
		cout<<"Enter first name"<<endl;
		cin>>fname;
		cout<<"Enter last name"<<endl;
		cin>>lname;
		cout<<"Enter date of birth"<<endl;
		cin>>dob;
		cout<<"Enter telephone number"<<endl;
		cin>>telno;
	}
	
	void setname(string fn,string ln)
	{
		fname=fn;
		lname=ln;
		dob="";
		telno="";
	}
	
	void display()
	{
		cout<<"Name is "<<fname<<" "<<lname<<endl;
	}
	
	bool compare(const Person &p1,const Person &p2)
	{
		if(p1.fname==p2.fname)
		{
			return (p1.lname<p2.lname);
		}
		else
		{
			return (p1.fname<p2.fname);
		}
	}
	
	bool operator = (const Person &p1,const Person &p2)
	{
		return (p1.fname==p2.fname?true:false);
	}
};

int main()
{
	list<Person> l;
	int choice;
	char ch='y';
	string fn,ln;
	Person p1,p2;
	while(ch=='y')
	{
		cout<<"Enter 1 to add an entry"<<endl;
		cout<<"Enter 2 to sort the list"<<endl;
		cout<<"Enter 3 to search a person"<<endl;
		cin>>choice;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter a value from 1 to 3"<<endl;
			cin>>choice;
		}
		switch(choice)
		{
			case 1:{
				    p1.accept();
					l.push_back(p1);
					break;
				   }
			case 2:{
					l.sort();
					list<Person>::iterator it1;
					it1=l.begin();
					while(it1!=l.end())
					{
						it1->display();
						it1++;
					}
					break;
				   }
			case 3:{
			        cout<<"Enter first name and last name to be searched"<<endl;
					cin>>fn>>ln;
					p2.setname(fn,ln);
					list<Person>::iterator it2;
					it2=l.begin();
					it2=find(l.begin(),l.end());
					if(it2!=l.end())
						it2->display();
					break;
				   }
		}
		cout<<"Do you want to continue? (y/n)"<<endl;
		cin>>ch;
	}
	return 0;
}*/

#include<iostream>
#include<list>
#include<iomanip>
using namespace std;

struct item
{
	int code;
	string name;
	int quantity;
	float price;
}obj;

bool compare(const item& first, const item& second)
{
	if (first.code < second.code)
		return true;
	else
		return false;
}

int main()
{
	int total=0;
    char ch='y';
	list<item> l;
	list<item>::iterator ptr1;
	int i=1;

	while(ch=='y')
	{
		cout<<"Enter item code,name,quantity and price of item "<<i<<endl;
		cin>>obj.code;
		cin>>obj.name>>obj.quantity>>obj.price;
		l.push_back(obj);
		total++;
		i++;
		cout<<"Do you want to continue?"<<endl;
		cin>>ch;
	}
	ptr1=l.begin();
	l.sort(compare);
	cout<<setw(5)<<"CODE"<<setw(15)<<"ITEM NAME"<<setw(10)<<"QUANTITY"<<setw(8)<<"PRICE"<<endl;
	ptr1 = l.begin();
	for(int i=0;i<total;i++,ptr1++)
	{
		cout<<setw(5)<<ptr1->code<<setw(15)<<ptr1->name<<setw(10)<<ptr1->quantity<<setw(8)<<ptr1->price<<"\n";
	}
	ptr1=l.begin();
	int tcode;
	bool flag=false;
	cout<<"Enter the code you want to search: :";
	cin>>tcode;
	for(int i=0;i<total;i++,ptr1++)
	{
		if(ptr1->code==tcode)
		{
			tcode=i;
			flag=true;
			break;
		}
	}
	if(flag)
	{
	    cout<<"Element found at position "<<tcode+1<<endl;
	}
	else
	{
	    cout<<"Element not found."<<endl;
	}
	return 0;
}


