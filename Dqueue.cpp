#include<iostream>
#include<deque>
using namespace std;

int main()
{
	deque <int> d; 
	int choice,ele;
	char ch='y';
	deque<int> :: iterator it;
	while(ch=='y')
	{
		cout<<"Press 1 to insert element at front of dequeue"<<endl;
		cout<<"Press 2 to insert element at rear of dequeue"<<endl;
		cout<<"Press 3 to delete element from front of dequeue"<<endl;
		cout<<"Press 4 to delete element from rear of dequeue"<<endl;
		cout<<"Press 5 to display the elements of dequeue"<<endl;
		cin>>choice;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter a value from 1 to 5"<<endl;
			cin>>choice;
		}
		switch(choice)
		{
			case 1: cout<<"Enter element"<<endl;
					cin>>ele;
					while(!cin)
					{
						cin.clear();
						cin.ignore(5,'\n');
						cout<<"Enter only integer values"<<endl;
						cin>>ele; 
					}
					d.push_front(ele);
					break;
			case 2: cout<<"Enter element"<<endl;
					cin>>ele;
					while(!cin)
					{
						cin.clear();
						cin.ignore(5,'\n');
						cout<<"Enter only integer values"<<endl;
						cin>>ele; 
					}
					d.push_back(ele);
					break;
			case 3: ele=d.front();
					d.pop_front();
					cout<<ele<<" deleted from front"<<endl;
					break;
			case 4: ele=d.back();
					d.pop_back();
					cout<<ele<<" deleted from back"<<endl;
					break;
			case 5: for(it=d.begin();it!=d.end();it++)
					{
						cout<<*it<<" ";
					}		
					cout<<endl;
					break;
			default:cout<<"Invalid choice"<<endl;
					break;
		}
		cout<<"Do you want to continue? (y/n)"<<endl;
		cin>>ch;
	}
	return 0;	
}
