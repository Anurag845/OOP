#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;
class data
{
	char name[20];
	long tele;
public:
	void get();
	void show();
	int update();
	void search();
	char* getname();
	long gettele();
	void number(long);
	void update_tele();
};
void data::update_tele()
{
	cout<<"\nEnter new telephone number:";
	cin>>tele;
}
void data::number(long n)
{
	tele=n;
}
char* data::getname()
{
	return name;
}
long data::gettele()
{
	return tele;
}
void data::get()
{
	cout<<"\nEnter name:";
	cin.getline(name,20);
	cout<<"\nTelephone no.:";
	cin>>tele;
}
void data::show()
{
	cout<<"\n"<<name<<"\t"<<tele;
}
void display()
{
	ifstream fi;
	data d;
	fi.open("tele.txt");
	fi.seekg(0);
	while(fi.read((char*)&d,sizeof(d)))
		{
			d.show();
		}
	fi.close();
}
int search_by_name(char str1[])
{
	ifstream fi;
	data d;
	int flag=0;
	fi.open("tele.txt");

	while(fi.read((char*)&d,sizeof(d)))
	{
		if(strcmp(str1,d.getname())==0)
		{
			cout<<"\nFound\nDetails:";
			flag=1;
			d.show();
		}
	}
	fi.close();
	return flag;

}
int search_by_tele(long n)
{
	int flag=0;
	ifstream fi;
	data d;
	fi.open("tele.txt");

	while(fi.read((char*)&d,sizeof(d)))
	{
		if(n==d.gettele())
		{
			cout<<"\nFound\nDetails:";
			flag=1;
			d.show();
		}
	}
	fi.close();
	return flag;
}
void add()
{
	data d;
	ofstream fo;
	fo.open("tele.txt",ios::app);
	d.get();
	fo.write((char*)&d,sizeof(d));
	fo.close();
}
int update(char str1[])
{
	data d;
	int flag=0,pos;
	fstream f;
	f.open("tele.txt",ios::in|ios::out|ios::ate);
	f.seekg(0);
	while(!f.eof())
	{
		f.read((char*)&d,sizeof(d));
		if(strcmp(str1,d.getname())==0)
		{
			cout<<"\nFound\nDetails:";
			flag=1;
			d.show();
			pos=f.tellg();
			pos-=sizeof(data);
			d.update_tele();
			f.seekp(pos);
			f.write((char*)&d,sizeof(d));
			break;
		}
	}
	f.close();
	return flag;
}
int main()
{
	int ch,check;
	long num;
	char ans,str[20];
	do
	{
		cout<<"\n1.Add to database\n2.Search by name\n3.Search by telephone no.\n4.Display\n5.Update";
		cin>>ch;
		cin.get();
		switch(ch)
		{
		case 1:
			add();
			break;
		case 2:
			cout<<"\nEnter the name of person:";
			cin.getline(str,20);
			check=search_by_name(str);
			if(!check)
			{
				cout<<"\nNot found";
			}
			break;
		case 3:
			cout<<"\nEnter telephone no.:";
			cin>>num;
			check=search_by_tele(num);
			if(!check)
			{
				cout<<"\nNot found";
			}

			break;
		case 4:
			display();
			break;
		case 5:
			cout<<"\nEnter the name of person:";
			cin.getline(str,20);
			check=update(str);
			if(!check)
			{
				cout<<"\nNot found";
			}
			else
				cout<<"\nUpdated!!";
			break;
		default:cout<<"\nWrong choice!!";
		}

		cout<<"\n\n\n\nPerform any other operation?";
		cin>>ans;
	}while(ans=='y');
}

