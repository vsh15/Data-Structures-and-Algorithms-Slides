//////////////////////////// Q4-a - Algorithm for Repetitive Data Generation//////////////////////////////////
// Name - Aneesh Abhyankar
// RUID - 166006555
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	ofstream data_file_;														// variable for output file
	data_file_.open("q4.txt");													// create and open file

	for (int i = 0; i < 1024; i++)												// loop runs 1024 times
	{
		cout << 1 << "\t";														
		data_file_ << 1 << endl;												// write 1 to file
	}
	
	for (int i = 0; i < 2048; i++)												// loop runs 2048 times
	{
		cout << 11 << "\t";
		data_file_ << 11 << endl;												// write 11 to file
	}
	

	for (int i = 0; i < 4096; i++)												// loop runs 4096 times
	{
		cout << 111 << "\t";
		data_file_ << 111 << endl;												// write 111 to file
	}
	
	for (int i = 0; i < 1024; i++)												// loop runs 1024 times
	{
		cout << 1111 << "\t";
		data_file_ << 1111 << endl;												// write 1111 to file
	}
	cout << endl;
	data_file_.close();															// close file

	system("pause");
	return 0;
}
