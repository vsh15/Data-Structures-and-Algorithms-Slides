///////////////////////////////// Q4 - Binary Search Tree //////////////////////////////////////
// Name - Aneesh Abhyankar
// RUID - 166006555
///////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<vector>
#include<fstream>

using namespace std;

struct nodeBST
{
	int data;
	int subtreeCount;
	nodeBST *left;
	nodeBST *right;
};


nodeBST *makeNode(int data)
{
	nodeBST *newNode = new nodeBST;
	newNode->data = data;
	newNode->subtreeCount = 1;
	newNode->left = newNode->right = NULL;
	return newNode;
}


void insertNode(int data, nodeBST *&root)
{
	if (root == NULL)
	{
		root = makeNode(data);
		//cout << data << "\t";
	}
	else if (root->data > data)
	{
		//root->subtreeCount += 1;
		insertNode(data, root->left);
	}
	else if (root->data < data)
	{
		//root->subtreeCount += 1;
		insertNode(data, root->right);
	}
	else
	{
		//	cout << root->data << " is repeated and hence is dropped" << endl;
	}
	return;

}


void printInorder(nodeBST *&root)
{
	if (root == NULL)
		return;

	if (root->left == NULL && root->right == NULL)
	{
		cout << root->data;
		cout << "\t";
	}
	else
	{
		printInorder(root->left);

		cout << root->data;
		cout << "\t";

		printInorder(root->right);
	}
}


void printSubtreeCount(nodeBST *&root)
{
	if (root == NULL)
		return;

	if (root->left == NULL && root->right == NULL)
	{
		cout << root->subtreeCount;
		cout << "\t";
	}
	else
	{
		printSubtreeCount(root->left);

		cout << root->subtreeCount;
		cout << "\t";

		printSubtreeCount(root->right);
	}
}


int updateSubtreeCount(nodeBST *&root)
{
	//int counter;

	if (root == NULL)
	{
		return 0;
	}
	else
	{
		root->subtreeCount = 1 + updateSubtreeCount(root->left) + updateSubtreeCount(root->right);
		return root->subtreeCount;
	}
}


int size(nodeBST *&root)
{
	if (root == NULL)
		return 0;
	return root->subtreeCount;
}


int rankOf(int data, nodeBST *&root)
{
	int rank = -1;
	int temp;
	if (root == NULL)
		return -1;
	if (root->data == data)
	{
		return (size(root->left));
	}
	else if (root->data > data)
	{
		rank = rankOf(data, root->left);
		return rank;
	}
	else
	{
		temp = rankOf(data, root->right);
		if (temp != -1)
			rank = size(root->left) + 1 + temp;
		return rank;
	}
	return rank;
}


int select(int lookForRank, nodeBST *&root)
{
	int lookFor = lookForRank;
	int temp = size(root->left);

	if (temp == lookForRank)
		return root->data;
	else if (temp > lookForRank)
	{
		return(select(lookForRank, root->left));
	}
	else
	{
		lookFor = lookForRank - temp - 1;
		return(select(lookFor, root->right));
	}

}


int main(int argc, char* argv[])
{
	//////////////// variable declarations //////////////
	nodeBST *root;
	root = NULL;
	vector<int> BSTdata;
	int key, size, BSTsize;
	int rank, keyForRank;
	int selectVar, keyForSelect;
	int j;
	/////////////////////////////////////////////////////


	/////////// data initialization /////////////////////

	ifstream file_(argv[1]);											// Opens the file

	if (file_.is_open())												// Checks if the file is open
	{
		while (file_ >> j)												// while there is data in the file it is stored in 'j'
		{
			BSTdata.push_back(j); 
			insertNode(j, root);										// Data is added to the vector
		}

		file_.close();													// Close the file
	}
	BSTsize = BSTdata.size();

	/////////////////////////////////////////////////////

	/*/////////////// Traversal //////////////////////////
	cout << "Inorder Traversal : \n";
	printInorder(root);
	cout << endl << endl;
	///////////////////////////////////////////////////*/


	/*//////////////// Subtree Count /////////////////////
	cout << "Printing Subtree Count : \n";
	printSubtreeCount(root);
	cout << endl << endl;*/

	updateSubtreeCount(root);
	//////////////////////////////////////////////////////


	//////////////////// Rank ///////////////////////////
	cout << "Enter Element to find Rank : ";
	cin >> keyForRank;
	rank = rankOf(keyForRank,root);
	if (rank == -1)
	cout << "Element not found" << endl;
	else
	cout << "Rank of " << keyForRank << " is : " << rank << endl;
	/////////////////////////////////////////////////////


	//////////////////// Select ///////////////////////////
	cout << "Enter Rank to find Element : ";
	cin >> keyForSelect;
	if (keyForSelect < 0 || keyForSelect > (BSTsize - 1))
	cout << "Rank out of range..." << endl;
	else
	{
	selectVar = select(keyForSelect, root);
	cout << "Element of Rank " << keyForSelect << " is : " << selectVar << endl;
	}
	/////////////////////////////////////////////////////
	ofstream output_file_;														// variable for output file
	output_file_.open("out.txt");
	output_file_ << rank << endl;
	output_file_ << selectVar << endl;


	system("pause");
	return 0;
}
