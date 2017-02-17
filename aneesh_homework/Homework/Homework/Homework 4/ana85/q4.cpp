///////////////////////////////////// Q4 - Red-black Tree //////////////////////////////////////
// Name - Aneesh Abhyankar
// RUID - 166006555
///////////////////////////////////////////////////////////////////////////////////////////////

// Reference - http://geeksquiz.com/c-program-red-black-tree-insertion/

///////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<ctime>

#define RED false
#define BLACK true

using namespace std;

int tempDepth = 0;
float numRed = 0;
float numBlack = 0;

struct RBNode
{
	int data;
	int depth;
	bool color;
	RBNode *left, *right, *parent;

	//Constructor
	RBNode(int data)
	{
		this->data = data;
		this->color = RED;
		left = right = parent = NULL;
		depth = 0;
	}

};


void leftRotate(RBNode *&root, RBNode *&pt)
{
	RBNode *pt_right = pt->right;

	pt->right = pt_right->left;

	if (pt->right != NULL)
		pt->right->parent = pt;

	pt_right->parent = pt->parent;

	if (pt->parent == NULL)
		root = pt_right;

	else if (pt == pt->parent->left)
		pt->parent->left = pt_right;

	else
		pt->parent->right = pt_right;

	pt_right->left = pt;
	pt->parent = pt_right;
}


void rightRotate(RBNode *&root, RBNode *&pt)
{
	RBNode *pt_left = pt->left;

	pt->left = pt_left->right;

	if (pt->left != NULL)
		pt->left->parent = pt;

	pt_left->parent = pt->parent;

	if (pt->parent == NULL)
		root = pt_left;

	else if (pt == pt->parent->left)
		pt->parent->left = pt_left;

	else
		pt->parent->right = pt_left;

	pt_left->right = pt;
	pt->parent = pt_left;
}


void fixViolation(RBNode *&root, RBNode *&newPtr)
{
	RBNode *parentPtr = NULL;
	RBNode *grandParentPtr = NULL;

	while (newPtr != root && newPtr->color != BLACK && newPtr->parent->color == RED)
	{
		parentPtr = newPtr->parent;
		grandParentPtr = newPtr->parent->parent;

		// CASE A : if parent is left child of grandParent
		if (parentPtr == grandParentPtr->left)
		{
			RBNode *unclePtr = grandParentPtr->right;

			// CASE A1 : if uncle is same color as parent, just recoloring is required
			if (unclePtr != NULL && unclePtr->color == RED)
			{
				grandParentPtr->color = RED;
				parentPtr->color = unclePtr->color = BLACK;
				newPtr = grandParentPtr;
			}
			else
			{
				// CASE A2 : if newNode is the right child of parent, left rotation (of parent) is required
				if (newPtr == parentPtr->right)
				{
					leftRotate(root, parentPtr);
					newPtr = parentPtr;										// swap back parent and newPtr
					parentPtr = newPtr->parent;
				}
				// CASE A3 : if newNode is left child of parent, right rotation (of grandParent) is required
				rightRotate(root, grandParentPtr);
				swap(parentPtr->color, grandParentPtr->color);
				newPtr = parentPtr;
			}
		}
		else
		{
			RBNode *unclePtr = grandParentPtr->left;

			// CASE B1 : if uncle is same color as parent, just recoloring is required
			if (unclePtr != NULL && unclePtr->color == RED)
			{
				grandParentPtr->color = RED;
				parentPtr->color = unclePtr->color = BLACK;
				newPtr = grandParentPtr;
			}
			else
			{
				// CASE B2 : if newNode is the left child of parent, right rotation (of parent) is required
				if (newPtr == parentPtr->left)
				{
					rightRotate(root, parentPtr);
					newPtr = parentPtr;										// swap back parent and newPtr
					parentPtr = newPtr->parent;
				}
				// CASE B3 : if newNode is right child of parent, left rotation (of grandParent) is required
				leftRotate(root, grandParentPtr);
				swap(parentPtr->color, grandParentPtr->color);
				newPtr = parentPtr;
			}
		}
	}
	root->color = BLACK;
}


RBNode *makeNode(int data)
{
	return new RBNode(data);
}


RBNode *insertNode(int data, RBNode *&root, RBNode *&parent)
{
	if (root == NULL)
	{
		root = makeNode(data);
		root->parent = parent;
		return root;
		
	}
	else if (root->data > data)
	{
		
		insertNode(data, root->left, root);
	}
	else if (root->data < data)
	{
		
		insertNode(data, root->right, root);
	}
	else
	{
		return NULL;
		
	}
}


void inorder(RBNode *root)
{
	if (root == NULL)
		return;

	if(root->left != NULL)
		root->left->depth = root->depth + 1;
	inorder(root->left);


	
	if (root->color == RED)
		numRed++;
	else
		numBlack++;

	if (root->right != NULL)
		root->right->depth = root->depth + 1;
	inorder(root->right);
}


void shuffle(vector<int> &a, int size)
{
	int r, temp;

	
	for (int i = 0; i < size; i++)
	{
		r = rand() % (i + 1);
		if (i != r)
		{
			temp = a[i];
			a[i] = a[r];
			a[r] = temp;
		}
	}

}


int depthTotal(RBNode *&root, int totalDepth)
{
	
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		totalDepth = root->depth;
	else
	{
		totalDepth = root->depth + depthTotal(root->left, totalDepth) + depthTotal(root->right, totalDepth);
	}
	return totalDepth;
}


int main(int args, char *argv[])
{
	////////////////////// Variables ////////////////////
	RBNode *root = NULL;
	RBNode *insertPtr, *initParent;

	vector<int> RBdata;

	string fileName;

	int RBsize;
	int index = 0;

	float percent;

	initParent = NULL;

	///////////////// Console i/o ///////////////////////
	cout << "Enter data size : ";
	cin >> RBsize;
	cout << "\nEnter output file name along with extension : ";
	cin >> fileName;
	////////////////////////////////////////////////////


	ofstream output_file_;														// variable for output file
	output_file_.open(fileName);												// create output file and open
	for (int k = 0; k < 1000; k++)
	{
		RBdata.clear();
		delete root;
		root = NULL;
		numRed = numBlack = 0;

		for (int j = 0; j < RBsize; j++)
		{
			RBdata.push_back(j);
		}
		shuffle(RBdata, RBsize);

		for (int j = 0; j < RBsize; j++)
		{
			insertPtr = insertNode(RBdata[j], root, initParent);										// Data is added to the vector
			if (insertPtr != NULL)
				fixViolation(root, insertPtr);
		}

		/////////////////////////////////////////////////////


		//////////////// Inorder Traversal ///////////////////
		inorder(root);
		cout << endl;
		//////////////////////////////////////////////////////

		/////////////// Percentage ///////////////////////////

		int totalDepth = depthTotal(root, 0);
		float avgDepth = totalDepth / (numRed + numBlack);
		cout << numRed + numBlack << "\t" << avgDepth << endl;
		output_file_ << avgDepth << "\n";




		//percent = numRed / (numRed + numBlack);
		//output_file_ << percent << "\n";
		//cout << RBsize << " " << k << " " << percent << endl;
		/////////////////////////////////////////////////////

	}
	output_file_.close();


	std::system("pause");
	return 0;
}