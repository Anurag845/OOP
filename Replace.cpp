#include <iostream>
#include <fstream>
using namespace std;

void s_replace(string& subject,const string& search,const string& replace) 
{
    size_t pos=0;
    while((pos=subject.find(search,pos))!=string::npos)
    {
         subject.replace(pos,search.length(),replace);
         pos+=replace.length();
    }
}

int main(int argc,char* argv[]) 
{
	if(argc!=4)
		cout<<"Invalid number of arguments"<<endl;
	else
	{
		ifstream ifile;
      	ifile.open(argv[3]);
      	string line;
     
      	string s = argv[1];
      	string r = argv[2];
      	string data;

      	if(ifile.is_open())
	  	{
      	      while(!ifile.eof())
      	      {
      	            getline(ifile,line);
      	            if(line.find(s)!=string::npos) 
      	            {
      	            	   s_replace(line,s,r); 
      	            }
      	            line += "\n";
      	            data += line;
      	      }          
           
            //cout << data;
      	      ifile.close();
      	}
      	else
      	{
      	      cout<<"Failed\n";
      	}

      	ofstream ofile;
      	ofile.open(argv[3]);
      	if(ofile.is_open())
      	{
      	      ofile<<data;
      	}
      	ofile.close();
      	cout<<"After modification"<<endl;
      	ifile.open(argv[3]);
      	if(ifile.is_open())
      	{
      		while(getline(ifile,line))
      		{
      			cout<<line<<endl;
      		}
      		ifile.close();
      	}
    }
    return 0;
}
