#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

class Teldir
{
	public:
	string name,telno;
	Teldir()
	{
		name="none";
		telno="none";
	}

	void getdata()
	{
		cout<<"Enter name"<<endl;
		cin>>name;
		cout<<"Enter telephone number"<<endl;
		cin>>telno;
	}

	void showdata()
	{
		cout<<"Name is: "<<name<<endl;
		cout<<"Telephone number is: "<<telno<<endl;
	}
	
	string retname()
	{
		return name;
	}

	string rettno()
	{
		return telno;
	}
};

	void showall()
	{
		Teldir t;
		ifstream ifile;
		string line;
		ifile.open("Teldir.txt",ios::in | ios::binary);
		if(ifile.is_open())
		{
		    ifile.seekg(0);
			while(getline(ifile,line))
			{
				cout<<line<<endl;
			}
		}
		else
			cout<<"Error opening file"<<endl;
		ifile.close();
	}

	void search_name()
	{
		Teldir t;
		string s,line;
		ifstream ifile;
		ifile.open("Teldir.txt",ios::in | ios::binary);
		if(ifile.is_open())
		{
			cout<<"Enter the name whose phone number is to be determined"<<endl;
			cin>>s;
			while(getline(ifile,line))
			{
				if(s==line)
				{
				    getline(ifile,line);
				    cout<<s<<"'s phone number is "<<line<<endl;
				    break;
				}
			}
		}
		else
			cout<<"Error opening file"<<endl;
		ifile.close();
	}

	void search_tno()
	{
		Teldir t;
		string s,line,prev;
		ifstream ifile;
		ifile.open("Teldir.txt",ios::in | ios::binary);
		if(ifile.is_open())
		{
			cout<<"Enter number to be searched"<<endl;
			cin>>s;
			while(getline(ifile,line))
			{
				if(s==line)
				{
				    cout<<s<<" is "<<prev<<"'s phone number"<<endl;
				    break;
				}
				prev=line;
			}
		}
		else 
			cout<<"Error opening file"<<endl;
		ifile.close();
	}

	void update()
	{
		Teldir t;
		fstream file;
		string s,line,data;
		file.open("Teldir.txt",ios::binary | ios::in | ios::out);
		if(file.is_open())
		{
			cout<<"Enter the telephone number to be updated"<<endl;
			cin>>s;
			while(getline(file,line))
			{
				if(s==line)
				{
					cout<<"Matched.Enter new phone number"<<endl;
					cin>>t.telno;
					file.seekg(-s.length()-1,ios::cur);
					file<<t.telno<<endl;
					break;
				}
			}
		}
		else
			cout<<"Error opening file"<<endl;
		file.close();
	}

int main()
{
	Teldir obj;
	fstream file;
	int choice;
	char ch='y';
	while(ch=='y')
	{
		cout<<"Enter 1 to add entries to database"<<endl;
		cout<<"Enter 2 to search database by name"<<endl;
		cout<<"Enter 3 to search database by telephone number"<<endl;
		cout<<"Enter 4 to update telephone number"<<endl;
		cout<<"Enter 5 to show the database"<<endl;
		cin>>choice;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter a value from 1 to 4"<<endl;
			cin>>choice;
		}
		switch(choice)
		{
		case 1: obj.getdata();
				file.open("Teldir.txt",ios::out | ios::app);
				if(file.is_open())
				{
				    file<<obj.name<<endl<<obj.telno<<endl;
					cout<<"Entry added"<<endl;
				}
				else
				{
					cout<<"Error opening file"<<endl;
				}
				file.close();
				break;
		case 2:search_name();
			   break;
		case 3:search_tno();
		   	   break;
		case 4:update();
			   break;
		case 5:showall();
			   break;
		default:cout<<"Invalid choice"<<endl;
				break;
		}
		cout<<"Do you want to continue? (y/n)"<<endl;
		cin>>ch;
	}
	return 0;
}
