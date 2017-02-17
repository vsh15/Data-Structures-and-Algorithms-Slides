//////////////////////////// Q1-a - Top-Down Merge Sort //////////////////////////////////
// Name - Aneesh Abhyankar
// RUID - 166006555
/////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<fstream>
#include<ctime>
#include<string>


using namespace std;

int comp = 0;																	// Counter for counting number of comparisons

void merge(vector <int> &a, vector <int> &aux, int low, int mid, int high)
{
	int i = low;																// Initialize pointers i-for left subarray
	int j = mid + 1;															// j-for right subarray
	int k = low;																// k-for traversal of the entire array
	
	while (k <= high)
	{
		if (a[i] > a[j])														// compare respective elements of left and right subarray	
		{
			comp++;																// increment counter
			aux[k] = a[j];														// copy element from the right subarray to auxiliary array
			j++;																// increment respective pointers
			k++;
		}

		else if (a[i] <= a[j])
		{
			comp++;
			aux[k] = a[i];														// copy element from the left subarray to auxiliary array
			i++;																// increment respective pointers
			k++;
		}

		if (i > mid)															// left subarray ran out of elements
		{
			while (j <= high)
			{
				aux[k] = a[j];													// copy remaining elements from right subarray
				j++;	
				k++;
			}
		}

		if (j > high)															// right subarray ran out of elements
		{
			while (i <= mid)
			{
				aux[k] = a[i];													// copy remaining elements from left subarray
				i++;
				k++;
			}
		}
	}
	return;
}


void mergeSort(vector <int> &a, vector <int> &aux, int low, int high)
{
	int lo, hi, mid;
	
	aux = a;																	// initialize auxiliary vector
	lo = low;																	// initialize lo pointer
	hi = high;																	// initialize hi pointer

	if (hi <= lo)																// base case
		return;

	mid = (hi + lo) / 2;														// calculate mid-pointer

	mergeSort(aux, a, lo, mid);													// call merge sort with left subarray
	mergeSort(aux, a, mid+1, hi);												// call merge sort with right subarray
	merge(aux, a, lo, mid, hi);													// merge results together
	
}

int main(int argc, char* argv[])
{
	vector <int> toSort, auxiliary;												// vector declaration
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

	
	mergeSort(toSort, auxiliary, 0, size-1);									// call mergesort

	ofstream output_file_;														// variable for output file
	output_file_.open("out.txt");												// create output file and open
		
	cout << comp << endl;														// print # of comparisons to console
	output_file_ << comp << endl;												// write to the output file


	for (int i = 0; i < size; i++)												// print to console and write to file the sorted data
	{
		cout << toSort[i] << "\n";
		output_file_ << toSort[i] << "\n";
	}
	cout << endl;
	output_file_.close();														// close the output file

	system("pause");
	return 0;

}