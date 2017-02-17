#include<iostream>
#include<vector>
#include<ctime>
#include<fstream>
#include<string>

using namespace std;


int get_root(vector<int> &vec, int a)									// Reference : Algorithms by R. Sedgewick and K. Wayne
{
	while (vec[a] != a)
	{
		a = vec[a];														// Go to the parent of parent until we terminate on the root
	}
	//cout << a << endl;
	return a;															// return root
}


bool is_connected(vector<int> &vec, int a, int b)						// Reference : Algorithms by R. Sedgewick and K. Wayne
{
	if (get_root(vec, a) == get_root(vec, b))							// if both roots are same, it means the elements are already connected
		return true;

	return false;
}


void make_union(vector<int> &vec, int a, int b)							// Reference : Algorithms by R. Sedgewick and K. Wayne
{
	
	int p = get_root(vec, a);											// Get root of one element
	int q = get_root(vec, b);											// Get root of other element
	vec[p] = q;															// make the roots same
	cout << a << " and " << b << " are now connected!" << endl;			// Thus they are now connected
}


int main()
{

	vector<int> id;													// Vector in which the input data read from the file is stored
	int inputRange =8192;
	int num1, num2;
	int pairNum = 1;
	int connectCount = 0;
	string fileName;												// Name of the input file to be accepted from the user
	
	cout << "Please make sure the input file (maximum value in input data should be 8192) is in the same folder as this executable." << endl;
	cout << "Enter file name with extension : ";
	cin >> fileName;												// Name of the input file is accepted from the user
	cout << endl;

	clock_t start = clock();										// Start Clock


	for (int i = 0; i <= inputRange; i++)							// Initialization : each element is connected to itself
	{
		id.push_back(i);
	}
	cout << endl;

	ifstream file_(fileName);										// Opens the file

	if (file_.is_open())											// Checks if the file is open
	{
		while (file_ >> num1 >> num2)								// while there is data in the file it is stored in 'num1' and 'num2'
		{
			//cout << "Pair Number : " << pairNum << "->  ";
			if (!is_connected(id, num1, num2))						// If the files are not already connected
				make_union(id, num1, num2);							// connect them
			else
			{
				connectCount++;										//counter that counts already connected pairs
				//cout << num1 << " and " << num2 << " are already connected!" << endl;
			}
			pairNum++;
		}
		file_.close();												// Close the file
	}
	cout << "# of pairs already connected : " << connectCount << endl;				// Display # of already connected pairs
	
	clock_t stop = clock();											// Stop Clock
	
	cout << "\n\nTotal Execution time is : " << (stop - start) << " ms" << endl;	// Display total execution time
			
	system("pause");
	cin.get();
}