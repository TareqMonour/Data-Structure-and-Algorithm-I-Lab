// C++ code to find a pair with given sum
// in a Balanced BST

#include <bits/stdc++.h>
using namespace std;
// A binary tree node
class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

class BinarySearchTree {

	// Root of BST
public:
	Node* root;

	// Constructor
	BinarySearchTree() { root = NULL; }
	/* A recursive function to insert a new key in BST */
	Node* insertRec(Node* root, int data)
	{

		/* If the tree is empty, return a new node */
		if (root == NULL) {
			root = new Node(data);
			return root;
		}

		/* Otherwise, recur down the tree */
		if (data < root->data)
			root->left = insertRec(root->left, data);
		else if (data > root->data)
			root->right = insertRec(root->right, data);

		return root;
	}

	// This method mainly calls insertRec()
	void insert(int key) { root = insertRec(root, key); }

	bool isPairPresent(Node* root, Node* temp, int target)
	{
		if (temp == NULL)
			return false;

		return search(root, temp, target - temp->data)
			|| isPairPresent(root, temp->left, target)
			|| isPairPresent(root, temp->right, target);
	}

	bool search(Node* root, Node* temp, int k)
	{

		if (root == NULL)
			return false;

		Node* c = root;
		bool flag = false;
		while (c != NULL && flag != true) {
			if (c->data == k && temp != c) {
				flag = true;
				cout << "Pair Found: " << c->data << " + "
					<< temp->data;
				return true;
			}
			else if (k < c->data)
				c = c->left;
			else
				c = c->right;
		}

		return false;
	}
};

// Driver function
int main()
{
	BinarySearchTree* tree = new BinarySearchTree();
	/*
			15
			/	 \
		10	 20
		/ \	 / \
		8 12 16 25 */
	tree->insert(15);
	tree->insert(10);
	tree->insert(20);
	tree->insert(8);
	tree->insert(12);
	tree->insert(16);
	tree->insert(25);

	bool test
		= tree->isPairPresent(tree->root, tree->root, 35);
	if (!test)
		cout << "No such values are found!";
}

//This code is contributed by Abhijeet Kumar(abhijeet19403)
