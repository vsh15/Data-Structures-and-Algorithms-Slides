//////////////////////////////// Q1 and Q2 - Two-Three Tree ////////////////////////////////////
// Name - Aneesh Abhyankar
// RUID - 166006555
///////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<fstream>

#define emptyDataVal -1000000

using namespace std;

int tempDepth = 0;
float numNodes = 0.0;


struct Node23
{
	int data1, data2;
	int depth;
	Node23 *left, *middle, *right;
};


Node23 *makeNode(int data)
{
	Node23 *newNode = new Node23;
	newNode->data1 = data;
	newNode->data2 = emptyDataVal;
	newNode->left = newNode->middle = newNode->right = NULL;
	newNode->depth = tempDepth + 1;
	numNodes++;
	return newNode;
}


void insertNode(int data, Node23 *&root)
{
	if (root == NULL)
	{
		root = makeNode(data);
	}

	else if (root->data2 == emptyDataVal)
	{
		if (data > root->data1)
		{
			root->data2 = data;
		}
		else if (data < root->data1)
		{
			root->data2 = root->data1;
			root->data1 = data;
		}
		else
		{
			;
		}
	}
	else if (root->data2 != emptyDataVal)
	{
		if (data < root->data1)
		{
			tempDepth = root->depth;
			insertNode(data, root->left);
		}
		else if (data > root->data2)
		{
			tempDepth = root->depth;
			insertNode(data, root->right);
		}
		else if (data > root->data1 && data < root->data2)
		{
			tempDepth = root->depth;
			insertNode(data, root->middle);
		}
		else
		{
			;
		}
		
	}
}


void printInorder(Node23 *&root)
{
	if (root == NULL)
		return;

	if (root->left == NULL && root->middle == NULL && root->right == NULL)
	{
		cout << root->data1 << "\t";
		if (root->data2 != emptyDataVal)
			cout << root->data2 << "\t";
	}
	else
	{
		printInorder(root->left);

		cout << root->data1 << "\t";

		printInorder(root->middle);


		if (root->data2 != emptyDataVal)
			cout << root->data2 << "\t";

		printInorder(root->right);
	}
}


int depthTotal(Node23 *&root, int totalDepth)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->middle == NULL && root->right == NULL)
		totalDepth = root->depth;
	else
	{
		totalDepth = root->depth + depthTotal(root->left, totalDepth) + depthTotal(root->middle, totalDepth) + depthTotal(root->right, totalDepth);
	}
	return totalDepth;
}


int main(int args, char *argv[])
{
	Node23 *root;
	root = NULL;
	int treeSize, j;
	int totalDepth;
	float avgDepth;
	vector<int> treeData;


	ifstream file_(argv[1]);
	
	if (file_.is_open())
	{
		while (file_ >> j)
		{
			treeData.push_back(j);
			insertNode(j, root);
		}

		file_.close();
	}

	treeSize = treeData.size();
	
	/////////////////////////////////////////////////////

	ofstream output_file_;														// variable for output file
	output_file_.open("out.txt");												// create output file and open

	totalDepth = depthTotal(root, 0);
	avgDepth = totalDepth / numNodes;
	cout << numNodes << "\t" << avgDepth << endl;

	output_file_ << avgDepth << "\n";

	output_file_.close();


	system("pause");
	return 0;
}