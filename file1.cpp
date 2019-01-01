#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	string info;
	ofstream ofile;
	ofile.open("Teldir.txt",ios::out);
	if(ofile.is_open())
	{
		int n;
		cout<<"Enter the number of entries"<<endl;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cout<<"Enter name"<<endl;
			cin>>info;
			ofile<<info<<" ";
			cout<<"Enter phone number"<<endl;
			cin>>info;
			ofile<<info<<endl;	
		}
		ofile.close();
	}
	else
		cout<<"Trouble opening file"<<endl;
	ifstream ifile;
	ifile.open("Teldir.txt",ios::in);
	if(ifile.is_open())
	{
		while(getline(ifile,info))
		{
			cout<<info<<endl;
		}
		ifile.close();
	}
	else
		cout<<"Trouble opening file"<<endl;
	return 0;
}
