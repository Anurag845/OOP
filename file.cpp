#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream ofile;
	ofile.open("MyFile.txt",ios::out);
	if(ofile.is_open())
	{
		cout<<"File open in write mode"<<endl;
		ofile<<"First line of file"<<endl;
		ofile<<"Second line of file"<<endl;
	}
	else
		cout<<"Error opening file"<<endl;
	ofile.close();
	ifstream ifile;
	string line;
	ifile.open("MyFile.txt",ios::in);
	if(ifile.is_open())
	{
		cout<<"File open in read mode"<<endl;
		while(getline(ifile,line))
		{
			cout<<line<<endl;
		}
	}
	else
		cout<<"Error opening file"<<endl;
	ifile.close();
	return 0;
}
