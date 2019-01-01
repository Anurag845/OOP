#include<iostream>
using namespace std;

class Personal
{
	protected:
	string name;
	int age;
	string dob;
	public:	
	Personal()
	{
		name="none";
		age=0;
		dob='\n';
	}
	
	void displayper()
	{
		cout<<"Name "<<name<<endl;
		cout<<"Age "<<age<<endl;
		cout<<"Date of birth "<<endl;
	}
};

class Academic
{
	protected:
	string qual;
	float HSC;
	public:
	Academic()
	{
		qual="none";
		HSC=0;
	}
	
	void displayaca()
	{
		cout<<"Qualification is "<<qual<<endl;
		cout<<"HSC percentage is "<<HSC<<endl;
	}	
};

class Professional
{
	protected:
	string post;
	string compname;
	public:
	Professional()
	{
		post="none";
		compname="none";
	}
	
	void displaypro()
	{
		cout<<"Company name is "<<compname<<endl;
		cout<<"Company post is "<<post<<endl;
	}
};


class biodata : public Personal,public Professional,public Academic
{
	public:
	void accept()
	{
		cout<<"Enter employee name"<<endl;
		cin>>name;
		cout<<"Enter employee age"<<endl;
		cin>>age;
		cout<<"Enter employee's date of birth"<<endl;
		cin>>dob;
		cout<<"Enter employee qualification"<<endl;
		cin>>qual;
		cout<<"Enter HSC percentage"<<endl;
		cin>>HSC;
		cout<<"Enter company name"<<endl;
		cin>>compname;
		cout<<"Enter post"<<endl;
		cin>>post;
	}
	
	void display()
	{
		this->displayper();
		this->displayaca();
		this->displaypro();
	}
};

int main()
{
	biodata b;
	b.accept();
	b.display();
	return 0;
}
