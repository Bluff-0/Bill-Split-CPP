#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;

struct node
{
	string name;
	int dr;
	int cr;
};

struct node Node[10];

void input(int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<"Name: ";
		cin>>Node[i].name;
		cout<<"Paid: ";
		cin>>Node[i].dr;
	}
}

int calculateTotal(int n)
{
	int temp=0;
	for(int i=0; i<n; i++)
		temp+=Node[i].dr;
	return temp;
}

void calculateGain(int cost, int n)
{
	for(int i=0; i<n; i++)
	{
		Node[i].cr= cost - Node[i].dr;
	}
}

void result(int cost, int n)
{
	cout<<endl<<endl<<"\tPer Head Cost is: "<<cost<<endl<<endl;
	cout<<"\tName\t\t\tDebit\t\t\tCredit"<<"\t\t\t\tListen to your Master"<<endl<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"\t"<<Node[i].name<<"\t\t\t"<<Node[i].dr<<"\t\t\t"<<Node[i].cr<<"\t\t\t\t";
		if(Node[i].cr > 0)
			cout<<"Pay "<<abs(Node[i].cr)<<" to your master"<<endl;
		else
			cout<<"Collect "<<abs(Node[i].cr)<<" from your master"<<endl;
	}
}

int main()
{
	int n;
	cout<<"Heads:  ";
	cin>>n;
	input(n);
	int Total= calculateTotal(n);
	int Headcost= Total/n;
	calculateGain(Headcost, n);
	result(Headcost, n);
	return 0;
}
