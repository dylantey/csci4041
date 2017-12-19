#include<iostream>
#include<string>
#include<map>
#include<list>
#include <algorithm>
#include <fstream>
using namespace std;

#define maxsize 100000

int main(int argc, const char * argv[]) 
{
	string str1[maxsize];
	int numElement = 0;
	
	ifstream input;
	input.open(argv[1]);
	if(input.fail())
	{
		cout << "ERROR: cannot open file!\n";
		return 0;
	}
	
	while(input >> str1[numElement])
	{
		++numElement;
	}
	input.close();

	char charListOption[maxsize];
	int totalChar = 26, bucketMax = 10;
	int newEnd = 0, beginBucket = 0, endBucket = 0;
	bool NewBucket = false;

	for (int i = 0; i < totalChar; i++)
	{
		charListOption[i] = i + 'A';
	}
	
	map<int, list <string> > bucket;
	
	for (int k = 0; k < numElement; k++)
	{
		char target = str1[k].at(0);
		for (int p = 0; p < totalChar; p++)
		{
			if (target == charListOption[p])
			{
				//check if over 10
				if (bucket[p].size() >= bucketMax) //for now
				{
					//more than one bucket for character existed

					beginBucket = p;

					for (int i = p; i < totalChar; i++)
					{
						if (target != charListOption[i])
						{
							if (bucket[i - 1].size() >= bucketMax) //last bucket of character full
							{
								endBucket = i;
								newEnd = i;
								++totalChar;
								NewBucket = true;
								break;
							}
							else //last bucket of character not full
							{
								endBucket = i - 1;
								newEnd = i - 1;
								break;
							}
						}
					}

					if (NewBucket)
					{
						NewBucket = false; //reset

						//shift
						//if no 2 bucket for C , meaning 2 C key in there
						for (int z = totalChar; z >= newEnd - 1; z--)
						{
							charListOption[z + 1] = charListOption[z];
						}

					}	
					
					bucket[newEnd].push_back(str1[k]);

					int numOfBucket = endBucket - beginBucket + 1;
					int numItems = numOfBucket * 2; //max
					string *waitingToBeSortedString = new string[numItems];

					//take everything out from list
					int counter = 0;
					for (int i = 0; i < numOfBucket; i++)
					{
						for (int j = 0; j < 2; j++)
						{
							if (bucket[beginBucket + i].size() == 0)
							{
								break;
							}
							waitingToBeSortedString[counter] = bucket[beginBucket + i].back();
							++counter;
							bucket[beginBucket + i].pop_back();
						}
					}

					sort(waitingToBeSortedString, waitingToBeSortedString + counter);

					int countPutBack = 0;
					for (int h = 0; h < numOfBucket; h++)
					{
						for (int i = 0; i < 2; i++)
						{
							bucket[beginBucket + h].push_back(waitingToBeSortedString[countPutBack]);
							++countPutBack;
							if (countPutBack == counter)
							{
								break;
							}
						}
					}

					break;
					
				}
				else
				{
					bucket[p].push_back(str1[k]);
					bucket[p].sort();
					break;
				}
			}
		}
	}

	ofstream outfile;
	outfile.open("output.txt");

	int counter = 0;
	for (int i = 0; i < totalChar; i++)
	{
		for (int j = 0; j < bucketMax; j++)
		{
			if (bucket[beginBucket + i].size() == 0)
			{
				break;
			}
			outfile<<bucket[beginBucket + i].back()<<" ";
			++counter;
			bucket[beginBucket + i].pop_back();
		}
	}	
	outfile << "\r\n";
	cout << "output.txt created!\n";
	outfile.close();
}