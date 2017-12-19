#include<iostream>
#include<string>
#include<fstream> 
using namespace std;

/*
	Dylan Tey
	5414524
	University of Minnesota - Twin Cities
*/

class node
{
public:
	node();
	node(char, int);
	node *next;
	node *left, *right;
	int data;
	char name;
};

node::node()
{
	data = NULL;
	name = NULL;
	next = NULL;
	left = NULL;
	right = NULL;
}

node::node(char n, int x)
{
	data = x;
	name = n;
	next = left = right = NULL;
}

class queue
{
public:
	queue();
	void InsertQueue(char, int);
	void InsertQueueNode(node*);

	node* Extract_Min_Node();

	void addingToTree();
	void generate(node *, string, char *, string *);
	void save(char *, string *, char, string);

	bool isEmpty()
	{
		return (front == NULL);
	}

	node *front;
};

queue::queue()
{
	front = NULL;
}

//MIN
void queue::InsertQueue(char n, int x)
{
	node* temp = new node(n, x);

	if (front == NULL || x < front->data)
	{
		temp->next = front;
		front = temp;
	}
	else
	{
		//lower priority than other people in the queue 
		node* p = front;
		while (p->next != NULL && p->next->data <= x)
		{
			p = p->next;
		}
		temp->next = p->next;
		p->next = temp;
		
	}
}

//MIN
void queue::InsertQueueNode(node* temp)
{
	int x = temp->data;
	if (front == NULL || x < front->data)
	{
		temp->next = front;
		front = temp;
	}
	else
	{
		//lower priority than other people in the queue 
		node* p = front;
		while (p->next != NULL && p->next->data <= x)
		{
			p = p->next;
		}
		temp->next = p->next;
		p->next = temp;

	}
}

node* queue::Extract_Min_Node()
{
	if (!isEmpty())
	{
		node *temp = front;
		front = front->next;
		return temp; //return min
	}
	else
	{
		return new node();
	}

}

void queue::addingToTree()
{
	
	while (true)
	{

		node *temp1 = Extract_Min_Node();
		node *temp2 = Extract_Min_Node();

		if (temp2->data == NULL) //when this happens, it means only one node left, and all are in the tree structure
		{
			InsertQueueNode(temp1);
			break;
		}

		node* new_temp = new node();
		new_temp->data = (temp1->data) + (temp2->data);
		new_temp->left = temp1;
		new_temp->right = temp2;
		
		//push value into Queue
		InsertQueueNode(new_temp);

	}
}

void queue::save(char *clist1, string *clist1_count, char c, string s)
{
	int j;
	for (j = 0; j < 26; j++) //find empty spot in array
	{
		if (clist1_count[j] == "")
		{
			break;
		}
	}
	clist1[j] = c;
	clist1_count[j] = s;
}

void queue::generate(node *n, string str, char *clst1, string *clist1_count)
{
	//recursion
	if (n != NULL )
	{
		if (n->name != NULL)
		{
			save(clst1, clist1_count, n->name, str);
		}
		generate(n->left, str + '0', clst1, clist1_count);
		generate(n->right, str + '1', clst1, clist1_count);
	}
}

int main(int argc, const char * argv[])
{
	string str1;
	queue *bst = new queue();

	//read file
	ifstream input;
	input.open(argv[1]);
	if (input.fail())
	{
		cout << "ERROR: cannot open file!\n";
		return 0;
	}
	input >> str1;
	input.ignore(20, '\n');
	input.close();

	const char *cstr = str1.c_str(); //change it to char array
	bool is_matched = false;

	char clist[26]; //count occurance of char in str1 string
	int count_char_string = str1.length(), clist_count[26], numElement = 0;
	
	for (int k = 0; k < 26; k++) //all elements' count to 0
	{
		clist_count[k] = 0;
	}

	for (int i = 0; i < count_char_string; i++)
	{
		for (int j = 0; j < (numElement + 1); j++) //add to clist and count
		{
			if (clist[j] == cstr[i])
			{
				++clist_count[j]; //element already existed in list
				is_matched = true;
			}
		}

		if (!(is_matched)) //element doesnt existed in list
		{
			clist[numElement] = cstr[i];
			clist_count[numElement] = 1;
			++numElement;
		}
		is_matched = false; //reset counter
	}

	//insert clist and count into queue
	for (int k = 0; k < numElement; k++)
	{
		bst->InsertQueue(clist[k], clist_count[k]);
	}

	bst->addingToTree();

	//values to be printed on text files are saved to these two arrays
	char c[26]; //this saves the character
	string clst1[26]; //this saves the end result, ie 0, 100, 101 etc

	for (int h = 0; h < 26; h++) //initialize
	{
		clst1[h] = "";
	}

	bst->generate(bst->front, "", c, clst1);

	//save to file
	ofstream outfile;
	outfile.open("output.txt");

	for (int l = 0; l < numElement; l++)
	{
		outfile << c[l] << ":" << clst1[l] << "\r\n";
	}

	cout << "output.txt created!\n";
	outfile.close();
}