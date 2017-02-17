/////////////// Q2b - Median of Three Quick Sort cuts off to Insertion Sort ////////////////////
// Name - Aneesh Abhyankar
// RUID - 166006555
///////////////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>

#define CUTOFF 15

using namespace std;

int comp = 0;

void insertionSort(vector<int> &a, int lo, int hi)
{
	for (int i = lo; i <= hi; i++)
	{
		for (int j = i; j > lo; j--)
		{
			comp++;
			if (a[j] < a[j - 1])
			{
				//swap a[j] and a[j-1]
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}

int medianOfThree(int a, int b, int c)
{
	int x = a - b;
	int y = b - c;
	int z = a - c;

	if (x*y > 0)
		return b;
	if (x*z > 0)
		return c;

	return a;
}

void quickSort(vector<int> &vec, int left, int right)
{
	int l = left;
	int r = right;
	int pivot;
	int temp;

	if (r <= l + CUTOFF - 1)
	{
		insertionSort(vec, l, r);
			return;
	}


	pivot = medianOfThree(vec[l], vec[(l + r) / 2], vec[r]);

	//////// Partition /////////
	while (l <= r)
	{
		while (vec[l] < pivot)
		{
			comp++;
			l++;
		}

		while (vec[r] > pivot)
		{
			comp++;
			r--;
		}

		if (l <= r)
		{
			temp = vec[r];
			vec[r] = vec[l];
			vec[l] = temp;
			l++;
			r--;
		}
	}

	if (left < r)
		quickSort(vec, left, r);
	if (l < right)
		quickSort(vec, l, right);

}

int main(int argc, char* argv[])
{
	vector<int> input;
	int j, size;
	int left = 0;


	ifstream file_(argv[1]);

	if (file_.is_open())
	{
		while (file_ >> j)
		{
			input.push_back(j);

		}
		file_.close();
	}
	size = input.size();
	int right = (input.size() - 1);

	clock_t start = clock();
	quickSort(input, 0, right);
	clock_t stop = clock();


	ofstream output_file_;														// variable for output file
	output_file_.open("out.txt");												// create output file and open

	cout << comp << endl;														// print # of comparisons to console
	output_file_ << comp << endl;												// write to the output file


	for (int i = 0; i < size; i++)												// print to console and write to file the sorted data
	{
		cout << input[i] << "\n";
		output_file_ << input[i] << "\n";
	}
	cout << endl;
	output_file_.close();														// close the output file

	cout << stop - start << endl;

	system("pause");
	return(0);
}


