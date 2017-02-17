///////////////////////////////////// Q3 - Heap Sort //////////////////////////////////////////
// Name - Aneesh Abhyankar
// RUID - 166006555
///////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<ctime>


using namespace std;



void max_heapify(vector<int> &a, int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2 * i;
	while (j <= n)
	{
		if (j < n && a[j + 1] > a[j])
			j = j + 1;
		if (temp > a[j])
			break;
		else if (temp <= a[j])
		{
			a[j / 2] = a[j];
			j = 2 * j;
		}
	}
	a[j / 2] = temp;
	
	return;
}


void buildMaxHeap(vector<int> &a, int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		max_heapify(a, i, n);
	}
}


void heapSort(vector<int> &a, int size)
{
	int temp;

	for (int i = size; i >= 2; i--)
	{
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;		
		max_heapify(a, 1, i - 1);
	}
}


int main(int argc, char* argv[])
{
	vector <int> toSort;										// vector declaration
	int size;															// size of vector
	int j;																// for traversing the input file

	toSort.push_back(0);
	ifstream file_(argv[1]);											// Opens the file

	if (file_.is_open())												// Checks if the file is open
	{
		while (file_ >> j)												// while there is data in the file it is stored in 'j'
		{
			toSort.push_back(j);										// Data is added to the vector
		}

		file_.close();													// Close the file
	}

	size = toSort.size() - 1;
	toSort[0] = size;
	//cout << size << endl;

	clock_t start = clock();
	buildMaxHeap(toSort, size);
	clock_t stop = clock();


	heapSort(toSort, size);
	clock_t end = clock();
	


	ofstream output_file_;														// variable for output file
	output_file_.open("out.txt");												// create output file and open


	for (int i = 1; i <= size; i++)												// print to console and write to file the sorted data
	{
		cout << toSort[i] << "\n";
		output_file_ << toSort[i] << "\n";
	}
	cout << endl;
	output_file_.close();														// close the output file

	

	cout << "Time: construction - " << stop - start << " ms" << endl;
	cout << "Time: total - " << end - start << " ms" << endl;
	
	system("pause");
	return 0;
}