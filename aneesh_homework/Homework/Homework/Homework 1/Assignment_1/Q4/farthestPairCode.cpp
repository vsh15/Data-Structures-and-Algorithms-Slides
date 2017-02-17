#include<iostream>
#include<ctime>

using namespace std;



double fRand(double fMin, double fMax)				// source : http://stackoverflow.com/questions/2704521/generate-random-double-numbers-in-c
{
	double f = (double)rand() / RAND_MAX;			// Generates random double values within a certain range 
	return fMin + f * (fMax - fMin);
}


int main()
{
	double arr[8192];									// Array in which random numbers are stored
	double min;
	double max;
	double difference;
	int size;
	bool correct = false;

	while (correct != true)
	{
		cout << "Input the size of the array (less than 8192): ";			//User enters size of array
		cin >> size;
		if (size > 8192)													// Check whether size is within limits 
		{
			cout << "Out of bounds..." << endl;
			correct = false;
		}
		else
			correct = true;
		cout << endl;
	}
	
	clock_t start = clock();												// Start Clock 

	for (int i = 0; i < size; i++)											// Initialization of aray to random double values
	{
		arr[i] = fRand(-500,500);
	}
	
	
	/*///////////////////////////////// Display the Array //////////////////////////////////
	cout << "The array is : \n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\n";
	}
	cout << endl;
	/////////////////////////////////////////////////////////////////////////////////////////*/
	
	max = min = arr[0];														// Initialize max and min as the first element of the array

	for (int i = 0; i < size; i++)											// Traverse the array once (so, complexity is O(n))
	{
		if (arr[i] > max)													// If element is greater than max
			max = arr[i];													// Make it as max
		if (arr[i] < min)													// If element is smaller than min
			min = arr[i];													// Make it as min		
	}

	difference = abs(max - min);											// Difference between the farthest pair
	cout << "Farthest Pair is : " << min << " and " << max << " and their difference is : " << difference << endl;
	
	clock_t end = clock();													// Stop Clock 
	
	cout << "\n\n" << "execution time : " << end - start << "ms" << endl;	//Display execution time

	system("pause");
	cin.get();
}
