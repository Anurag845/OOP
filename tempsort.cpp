#include<iostream>
using namespace std;

template <typename T>
void sSort(T *p,int n)
{
	int i,j,min;
	T temp;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i;j<n;j++)
		{
			if(p[j]<p[min])
				min=j;
		}
		temp=p[min];
		p[min]=p[i];
		p[i]=temp;
	}
	for(int i=0;i<n;i++)
	{
		cout<<p[i]<<" ";
	}
}

int main()
{
	char c='y';
	int ch,n1,n2;
	while(c=='y' || c=='Y')
	{
		cout<<"Enter 1 to perform sorting operation on an integer array"<<endl;
		cout<<"Enter 2 to perform sorting operation on an float array"<<endl;
		cin>>ch;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter a value between 1 and 2"<<endl;
			cin>>ch;
		}
		switch(ch)
		{
			case 1: {
					cout<<"Enter size of array"<<endl;
					cin>>n1;
					while(!cin)
					{
						cin.clear();
						cin.ignore(5,'\n');
						cout<<"Enter an integer value"<<endl;
						cin>>n1;
					}
					int *p1=new int[n1];
					cout<<"Enter array elements"<<endl;
					for(int i=0;i<n1;i++)
					{
						cin>>p1[i];
					}
					sSort(p1,n1);
					break;
					}
			case 2: {
					cout<<"Enter size of array"<<endl;
					cin>>n2;
					while(!cin)
					{
						cin.clear();
						cin.ignore(5,'\n');
						cout<<"Enter an integer value"<<endl;
						cin>>n2;
					}
					float *p2=new float[n2];
					cout<<"Enter array elements"<<endl;
					for(int i=0;i<n2;i++)
					{
						cin>>p2[i];
					}
					sSort(p2,n2);
					break;
					}
			default: {
					 cout<<"Invalid choice"<<endl;
					 break;
					 }
		}
		cout<<endl<<"Do you want to continue? (y/n)"<<endl;
		cin>>c;
	}
	return 0;
}

