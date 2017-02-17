#include<iostream>
#include<vector>
#include<fstream>
#include<ctime>
#include<string>

using namespace std;

bool is_connected(vector<int> &vec, int a, int b)					// Reference : Algorithms by R. Sedgewick and K. Wayne
{
	if (vec[a] == vec[b])											// If the values at the indices are equal it menas the elements are connected
		return true;												// So, return true
	else
		return false;												// else return false, i.e. they are not connected
}

void make_union(vector<int> &vec, int a, int b)						// Reference : Algorithms by R. Sedgewick and K. Wayne
{
	int id_a = vec[a];												// Store the parent of the first element				
	int id_b = vec[b];												// Store the parent of the first element

	for (int i = 0; i < vec.size(); i++)							// Loop over the entire vector
	{
		if (vec[i] == id_a)											// Change all the parent values		
			vec[i] = id_b;	
	}
	cout << a << " and " << b << " are now connected!" << endl;		// hus, the two elements are connected
}

int main()
{

	vector<int> id;												// Vector in which the input data read from the file is stored
	int num1, num2;
	int inputRange = 8192;
	int pairNum = 1;
	int connectCount = 0;
	string fileName;											// Name of the input file to be accepted from the user

	cout << "Please make sure the input file (maximum value in input data should be 8192) is in the same folder as this executable." << endl;
	cout << "Enter file name with extension : ";
	cin >> fileName;											// Name of the input file is accepted from the user

																// Start Clock 
	clock_t start = clock();


	for (int i = 0; i <= inputRange; i++)						// Initialization : each element is connected to itself
	{
		id.push_back(i);
	}

	ifstream file_(fileName);												// Opens the file
		
	if (file_.is_open())													// Checks if the file is open
	{
		while (file_ >> num1 >> num2)										// while there is data in the file it is stored in 'num1' and 'num2'
		{
			//cout << "Pair Number : " << pairNum << "->  ";
			if (!is_connected(id, num1, num2))								// If the files are not already connected
				make_union(id, num1, num2);									// connect them
			else
			{
				connectCount++;												//counter that counts already connected pairs		
				//cout << num1 << " and " << num2 << " are already connected!" << endl;
			}
			pairNum++;

		}
		file_.close();														// Close the file
	}

	cout << "# of pairs already connected : " << connectCount << endl;		// Display # of already connected pairs
	
	clock_t stop = clock();													// Stop Clock			
	
	cout << "\n\nTotal Execution time is : " << (stop - start) << " ms" << endl;	// Display total execution time
	
	system("pause");
	cin.get();
}