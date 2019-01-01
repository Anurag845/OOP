#include<iostream>
#include<fstream>
using namespace std;

void s_replace(string &subject,const string &search,const string &replace)
{
	size_t pos=0;
	while((pos=subject.find(search,pos))!=string::npos)
	{
		subject.replace(pos,search.length(),replace);
		pos+=replace.length();
	}
}

int main(int argc, char* argv[])
{
	string line,data;
	string s=argv[1];
	string r=argv[2];
	ifstream ifile;
	ifile.open(argv[3]);
	if(!ifile.is_open())
	{
		cout<<"Error opening file"<<endl;
	}
	else
	{
		while(!ifile.eof())
		{
			getline(ifile,line);
			if(line.find(s)!=string::npos)
			{
				s_replace(line,s,r);
			}
			line+='\n';
			data+=line;
		}
		ifile.close();
	}
	ofstream ofile;
	ofile.open(argv[3]);
	if(ofile.is_open())
	{
		ofile<<data;
	}
	else 
	{
		cout<<"Error modifying"<<endl;
	}
	ofile.close();
	ifile.open(argv[3]);
	if(ifile.is_open())
	{
		while(getline(ifile,line))
		{
			cout<<line<<endl;
		}
		ifile.close();
	}
	else
	{
		cout<<"Error reading file"<<endl;
	}
	return 0;
}
