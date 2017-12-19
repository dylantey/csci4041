#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<sstream>
#include<fstream> 
#include<string>
using namespace std;

/*
	Dylan Tey
	University of Minnesota - Twin Cities
	5414524
*/

class node
{
public:
	node(string, int);
	node *next;
	int data;
	string name;
};

node::node(string n, int x)
{
	data = x;
	name = n;
	next = NULL; //by data (priority/value)
}

class queue
{
public:
	queue();
	void Insert(string, int);
	string Extract_Max();

	bool isEmpty()
	{
		return (front == NULL);
	}

private:
		node *front;	
};

queue::queue()
{
	front =  NULL;
}

void queue::Insert(string n, int x)
{
	node* temp = new node(n, x);

	if (front == NULL || x > front->data)
	{
		temp->next = front;
		front = temp;
	}
	else
	{
		//higer priority than other people in the queue 
		node* p = front;
		while (p->next != NULL && p->next->data >= x)
		{
			p = p->next;
		}
		temp->next = p->next;
		p->next = temp;
	}

}

string queue::Extract_Max()
{
	if (!isEmpty())
	{
		node *temp = front;
		front = front->next;
		return temp->name; //return name
	}
}

int main(int argc, const char * argv[])
{
	int inputInt = 0;
	string inputName = "";
	string delim = "";
	int count = 0;
	queue *bank = new queue();

	//load file
	ifstream input;
	input.open(argv[1]);
	if (input.fail())
	{
		cout << "ERROR: cannot open file!\n";
		return 0;
	}

	while (input >> inputName >> delim >> inputInt) //delim is useless, just used to take the colon
	{
		bank->Insert(inputName, inputInt);
		++count;
	}
	input.close();

	//export to output file
	ofstream outfile;
	outfile.open("output.txt");
	for(int i=0; i < count; i++)
	{
		outfile << bank->Extract_Max() << " ";
	}
	outfile << "\r\n"; //linux version of new line "\r\n"
	cout << "output.txt created!\n";
	outfile.close();
}
