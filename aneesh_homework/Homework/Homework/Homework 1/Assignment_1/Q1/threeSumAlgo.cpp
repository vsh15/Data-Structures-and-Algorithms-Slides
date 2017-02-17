#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>
#include<string>


using namespace std;

int findTriplets(int num, vector<int> &a)						// Function to find the Triplets (A+B-C = 0)
{
	int count = 0;												// Count initialized to 0. This stores the number of triplets found	
	for (int i = 0; i < num; i++)
		for (int j = i + 1; j < num; j++)						// Points to one of the number in the triplet
			for (int k = 0; k < num; k++)						// Points to the second number in the triplet
				if (i != k && j != k)							// Points to the third number in the triplet
				{
					if (a.at(i) + a.at(j) == a.at(k))			// Checks if (A + B = C)
					{
						count++;								// Increment the counter if a triplet is found
						//cout << "Pair number " << count << ":\t" << a.at(i) << ", " << a.at(j) << ", " << a.at(k) << endl;
					}
				}
				
	return count;												// Return the counter value

}

int main()
{
	vector<int> threeSumInput;									// Vector in which the input data read from the file is stored
	int j;
	string fileName;											// Name of the input file to be accepted from the user 

	cout << "Please make sure the input file is in the same folder as this executable." << endl;
	cout << "Enter file name with extension : ";
	cin >> fileName;											// Name of the input file is accepted from the user

	clock_t start = clock();									// Start the clock to measure execution time

	ifstream file_(fileName);									// Opens the file

	if (file_.is_open())										// Checks if the file is open		
	{
		while (file_ >>  j)										// while there is data in the file it is stored in 'j'
		{
			threeSumInput.push_back(j);							// Data is added to the vector
		}

		file_.close();											// Close the file
	}
		
	
	int n = threeSumInput.size();								// Gives the size of the vector
	//cout << "Number of Input Values: " << n << endl;

	int count = findTriplets(n, threeSumInput);					// Function is called and it returns the number of triplets found
	
	cout << "Total 3-sum triplets are: " << count << endl;
	
	clock_t end = clock();										// Stop the clock
	cout << "\n\n" << "execution time : " << end - start << endl;		// Display the execution time

	system("pause");
	cin.get();
}