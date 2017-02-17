#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>
#include<string>

using namespace std;

void quickSort(vector<int> &vec, int left, int right)				// Reference : http://www.algolist.net/Algorithms/Sorting/Quicksort
{
	int l = left;													// Pointer for the leftmost index of the part of vector in question
	int r = right;													// Pointer for the rightmost index of the part of vector in question
	int pivot = vec[(l + r) / 2];									// Assume the pivot to be the midpoint of left and right
	int temp;

	//////// Partition /////////
	while (l <= r)													// while left < right
	{
		while (vec[l] < pivot)										// While value at left index is less than pivot
			l++;													// Move the pointer to the right

		while (vec[r] > pivot)										// While value at right index is greater than pivot
			r--;													// Move the pointer to the left

		if (l <= r)													// if left pointer is less than right pointer
		{															// Swap elements at left and right	
			temp = vec[r];
			vec[r] = vec[l];
			vec[l] = temp;
			l++;
			r--;
		}
	}

	if (left < r)													// Conditions for recursion
		quickSort(vec, left, r);
	if (l < right)
		quickSort(vec, l, right);
}


int binarySearch(vector<int> &vec, int first, int last, int query)		// Reference : http://mycodinglab.com/binary-search-algorithm-c/
{
	int index;															// It will store the index of the element to be searched 
	int mid;															// Points to the midpoint of the portion of vector in question

	if (first > last)													// If left pointer is greater than right pointer, it means we have not found the element		
	{
		index = -1;														// Return -1 meaning that element not found. This is the base case
	}
	else
	{
		mid = (first + last) / 2;										// Set mid point
			
		if (query == vec[mid])											// If required element is at mid, means we found the element
		{
			index = mid;												// return mid, i.e. index of the element. This is the base case
		}
		else
		{
			if (query < vec[mid])										// If required element is less than that at mid, means our required element is in the left half of the vector		
			{
				index = binarySearch(vec, first, (mid - 1), query);		// pass the left half of the vector to the recursive function 
			}
			else														// If required element is greater than that at mid, means our required element is in the right half of the vector
			{
				index = binarySearch(vec, (mid + 1), last, query);		// pass the right half of the vector to the recursive function 
			}															
		}
	}
	return index;														// Return index of the required element 
}


int main()
{

	vector<int> threeSumInput;								// Vector in which the input data read from the file is stored
	int j, n, x, k;
	int count = 0;
	int temp;
	string fileName;										// Name of the input file to be accepted from the user

	cout << "Please make sure the input file is in the same folder as this executable." << endl;
	cout << "Enter file name with extension : ";
	cin >> fileName;										// Name of the input file is accepted from the user

	clock_t start = clock();								// Start the clock to measure execution time

	ifstream file_(fileName);								// Opens the file

	if (file_.is_open())									// Checks if the file is open
	{
		while (file_ >> j)									// while there is data in the file it is stored in 'j'
		{
			threeSumInput.push_back(j);						// Data is added to the vector
		}

		file_.close();										// Close the file
	}

	n = threeSumInput.size();								// Gives the size of the vector

	quickSort(threeSumInput, 0, n - 1);						// Call the sorting function
	//insertion_sort(threeSumInput,n);

	for (int i = 0; i < n; i++)								// Points to one of the number in the triplet
		for (int j = i + 1; j < n; j++)						// Points to the second number in the triplet
		{
			temp = threeSumInput[i] + threeSumInput[j];		// Sum of two numbers
			x = binarySearch(threeSumInput, 0, (n - 1), temp);		//Search this sum in the vector using searching algorithm
			if (x != -1)									// Means that the number is found in the vector
			{
				count++;									// Increment the counter
				k = 1;
				while ((x + k < n) && (threeSumInput[x + k] == threeSumInput[x]))			// Searches for repetitions to the right of the number
				{
					count++;
					k++;
				}
				k = 1;
				while ((x - k >= 0) && (threeSumInput[x - k] == threeSumInput[x]))			// Searches for repetitions to the left of the number	
				{
					count++;
					k++;
				}
			}
		}
	cout << "Total 3-sum triplets are: " << count << endl;									// Display total triplets found

	clock_t end = clock();																	// Stop the clock
	cout << "\n\nexecution time : " << end - start << endl;									// Display execution time			
	
	system("pause");
	cin.get();

}