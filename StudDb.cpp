#include <iostream>
using namespace std;

class student
{
	int rno;
	string name,subject;
public:
	student()
    {
		rno=0;
		name="none";
		subject="none";
    }
	student(int r,string a,string b)
	{
		rno=r;
		name=a;
		subject=b;
	}
	friend class exam;
};

class exam
{
	int subcode,intmarks,unimarks;
public:
	void accept(int m,student* stud,exam* ex)
	{
		int i;
		for(i=0;i<m;i++)
		{
			cout<<"Enter student roll number:-";
			cin>>stud[i].rno;
			cout<<"Enter student name:-";
			cin>>stud[i].name;
			cout<<"Enter subject name:-";
			cin>>stud[i].subject;
			cout<<"Enter the subject code:-";
			cin>>ex[i].subcode;
			cout<<"Enter the internal assessment marks:-";
			cin>>ex[i].intmarks;
			cout<<"Enter the university exam marks:-";
			cin>>ex[i].unimarks;
			cout<<endl;
		}
	}
	void display(int m,student* stud,exam* ex)
	{
		int i;
		for(i=0;i<m;i++)
		{
			cout<<endl<<"For student "<<i+1<<endl;
			cout<<"Student roll number:-"<<stud[i].rno<<endl;
			cout<<"Student name:-"<<stud[i].name<<endl;
			cout<<"Subject name:-"<<stud[i].subject<<endl;
			cout<<"Subject code is:-"<<ex[i].subcode<<endl;
			cout<<"Internal assessment marks are:-"<<ex[i].intmarks<<endl;
			cout<<"University exam marks are:-"<<ex[i].unimarks<<endl;
		}
	}
};

int main()
{
	int m;
    cout<<"Enter number of students"<<endl;
	cin>>m;
    student* stud=new student[m];
    exam* ex=new exam[m];
    exam e;
    e.accept(m,stud,ex);
    e.display(m,stud,ex);
	return 0;
}
