//////////////////////////// Q4-b - Insertion Sort Algorithm on Repetitive Data //////////////////////////////////
// Name - Aneesh Abhyankar
// RUID - 166006555
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int counter = 0;

void insertionSort(vector<int> &a)
{
	int n = a.size();

	for (int i = 0; i < n; i++)														// points to sorted part of the array
	{
		for (int j = i; j > 0; j--)													// pointer for finding the correct spot for the next element to insert into the sorted part of the array
		{
			counter++;
			if (a[j] < a[j - 1])													// compare element with previous
			{
				int temp = a[j];													// swap if inverted
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
			else
				break;																// get out of the loop if not inverted
		}
	}
}


int main(int argc, char* argv[])
{
	vector <int> toSort;

	int size;																	// size of vector
	int j;																		// for traversing the input file


	ifstream file_(argv[1]);													// Opens the file

	if (file_.is_open())														// Checks if the file is open
	{
		while (file_ >> j)														// while there is data in the file it is stored in 'j'
		{
			toSort.push_back(j);												// Data is added to the vector
		}

		file_.close();															// Close the file
	}
	size = toSort.size();

	insertionSort(toSort);														// call insertionSort

	ofstream output_file_;														// variable for output file
	output_file_.open("out.txt");												// create output file and open

	for (int i = 0; i < size; i++)
	{
		output_file_ << toSort[i] << endl;										// write to output file
		cout << toSort[i] << endl;												// print on console
	}
	output_file_.close();														// close output file

	//cout << counter << endl; 

	system("pause");
	return 0;
}


