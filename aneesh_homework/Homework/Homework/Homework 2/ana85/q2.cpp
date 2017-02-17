//////////////////////////// Q2 - Shell Sort //////////////////////////////////
// Name - Aneesh Abhyankar
// RUID - 166006555
///////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<string>

using namespace std;

int counter = 0;


void insertionSort(vector<int> &a, int h)
{
	int n = a.size();
	int k = 0;																	// repetition pointer
	

	while (k < h)																// repeat h times
	{
		for (int i = k; i < n; i += h)											// points to sorted part of the array
		{
			for (int j = i; j >= h; j -= h)										// pointer for finding the correct spot for the next element to insert into the sorted part of the array
			{
				counter++;														// increment the comparison counter
				if (a[j] < a[j - h])											// compare element with previous (considering 'h' spacing)
				{
					int temp = a[j];											// swap if inverted
					a[j] = a[j - h];
					a[j - h] = temp;
				}
				else
					break;														// get out of the loop if not inverted
			}
		}
		k++;																	// increment k
	}
}

void shellSort(vector <int> &a)
{
	int n = a.size();															
	int h;																		// declare h variable

	for (int i = 3; i > 0; i--)													
	{
		h = pow(2, i) - 1;														// updating h value {7, 3, 1}
		insertionSort(a, h);													// call insertion sort with respective value of h	
	}

}


int main(int argc, char* argv[])
{
	vector <int> toSort;														// vector declaration
	int size;																	// size of vector
	int j, n;																	// for traversing the input file
	
	ifstream file_(argv[1]);													// Opens the file

	if (file_.is_open())														// Checks if the file is open
	{
		while (file_ >> j)														// while there is data in the file it is stored in 'j'
		{
			toSort.push_back(j);												// Data is added to the vector
		}

		file_.close();															// Close the file
	}
	n = toSort.size();

	shellSort(toSort);															// call shellSort

	ofstream output_file_;														// variable for output file
	output_file_.open("out.txt");												// create output file and open

	output_file_ << counter << endl;											// print counter value to output file
	cout << counter << endl;													// print counter value to console	

	for (int i = 0; i < n; i++)
	{
		output_file_ << toSort[i] << "\n";										// print sorted elements to output file and console
		cout << toSort[i] << "\n";
	}
	cout << endl; 
	output_file_.close();														// close the output file

	system("pause");
	return 0;

}