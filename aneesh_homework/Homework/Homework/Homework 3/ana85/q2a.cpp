//////////////////////////// Q2a - Median of Three Quick Sort /////////////////////////////////
// Name - Aneesh Abhyankar
// RUID - 166006555
///////////////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>

using namespace std;

int swaps = 0;
int comp = 0;

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
			if (l != r)
			{
				swaps++;
				temp = vec[r];
				vec[r] = vec[l];
				vec[l] = temp;
			}
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
	int j;
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
	int size = input.size();

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


	cout << stop-start << " ms" <<  endl;
	
	system("pause");
	return(0);
}


