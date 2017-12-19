#include <iostream>
#include <fstream>
using namespace std;

#define maxsize 1000000

void selectionsort(int array[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i; //set min to be index of i
		bool swapped = false;
		//compare
		for (int j = i + 1; j < n; j++)
		{
			//find index of smallest value in array
			if (array[min] > array[j])
			{
				min = j;
				swapped = true;
			}
		}

		//if swap occured, i is no longer the smallest
		if (swapped)
		{
			//swap
			int temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}

		swapped = false; //reset bool counter
	}
}

int main(int argc, const char * argv[])
{
	int i, count = 0, arr[maxsize];

	//load input file
	ifstream input;
	input.open(argv[1]);
	if (input.fail())
	{
		cout << "ERROR: cannot open file!\n";
		return 0;
	}
	input >> i; //index wanted

	//loading numbers into arr
	while (input >> arr[count])
	{
		count++;
	}
	input.close();

	//int length_of_arr = sizeof(arr) / sizeof(int);
	selectionsort(arr, count); //sorting

	//export to output file
	ofstream outfile;
	outfile.open("output.txt");
	outfile << arr[i - 1];
	outfile << "\r\n"; //linux version of new line "\r\n"
	cout << "output.txt created!\n";
	outfile.close();

}