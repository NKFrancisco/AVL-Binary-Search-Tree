////
// Author:       Nick Francisco 
// Section:      Online 2854
// Assignment:   Lab 2 AVL
// Description:  Creates AVL Tree with insert, printTree, and
//	functions to help balance the tree as inserting	 				
//
////

#include "BSTInterface.h"
#include <string>

using namespace std;
template <typename KeyComparable, typename Value >
class BinarySearchTree : BSTInterface < KeyComparable, Value > {
private:
	/*
	* Private Node Class 
	*
	*/
	class BinaryNode
	{
		public:
			KeyComparable key;
			Value value;

			BinaryNode *left;
			BinaryNode *right;
			//Initialize class members from constructor arguments 
			//by using a member initializer list.
			//This method uses direct initialization, which is more
			//efficient than using assignment operators inside the constructor body.
			BinaryNode(KeyComparable & key, Value & value, BinaryNode *left = nullptr, BinaryNode *right = nullptr)
				: value{ value }, left{ left }, right{ right } , key{ key }
			{
			}

	};
	// the root node of the tree
	BinaryNode *root = nullptr;

	/*
	* Inserts a node into the tree
	* returns true if item inserted
	* returns false if item not inserted (Key already in tree)
	* maintains this property of th tree:
	*     All nodes to the left will be less
	*     All nodes to the right will be greater
	*
	*/
	BinaryNode* insert(Value item, KeyComparable key, BinaryNode*& node)
	{
		//First item 
		if (node == root && root == nullptr) {
			BinaryNode* temp = new BinaryNode(key, item, nullptr, nullptr);
			root = temp;
		}
		else {
			if (node == nullptr) {
				node = new BinaryNode(key, item, nullptr, nullptr);
			}
			else if (key < node->key) {
				node->left = insert(item, key, node->left);
			}
			else if (key > node->key) {
				node->right = insert(item, key, node->right);
			}
			else if (key == node->key) 
				return nullptr;
			
			balanceTree(node);

			return node;
		}
	}


	//Const for print function
	int nodeHeightPrint(BinaryNode*& node) const {

		int left, right;

		if (node == nullptr)
			return -1;

		left = nodeHeightPrint(node->left);
		right = nodeHeightPrint(node->right);

		if (left > right)
			return left + 1;
		else
			return right + 1;
	}

	//Determines balance factor for node 
	int balanceFactorPrint(BinaryNode*& node) const {

		int left = nodeHeightPrint(node->left);
		int right = nodeHeightPrint(node->right);
		int bf = left - right;

		return bf;
	}

	//Returns height of node
	int nodeHeight(BinaryNode*& node) {

		int left, right; 

		if (node == nullptr)
			return -1;

		left = nodeHeight(node->left);
		right = nodeHeight(node->right);

		if (left > right)
			return left + 1;
		else
			return right + 1;
	}

	//Determines balance factor for node 
	int balanceFactor(BinaryNode*& node)  {

		int left = nodeHeight(node->left);
		int right = nodeHeight(node->right);
		int bf = left - right ;

		return bf;
	}

	//Balances Node 
	void balanceTree(BinaryNode*& node) {

		int bf = balanceFactor(node);

		if (bf > 1) {
			if (balanceFactor(node->left) > 0)
				node = RightRotate(node); //LL
			else {
				node->left = LeftRotate(node->left);
				node = RightRotate(node); //LR
			}
		}
		else if (bf < -1) {
			if (balanceFactor(node->right) > 0) {
				node->right = RightRotate(node->right); //RL
				node = LeftRotate(node);
			}
			else 
				node = LeftRotate(node); //RR
				
		}
	}

	//Left Rotate
	BinaryNode* LeftRotate(BinaryNode* node) {

		BinaryNode* child = node->right;

		node->right = child->left;
		child->left = node;

		//Chaniging root
		if (node == root) 
			root = child; 

		return child;
	}

	//Right Rotate
	BinaryNode* RightRotate(BinaryNode* node) {

		BinaryNode* child = node->left;		

		node->left = child->right;
		child->right = node;

		//Chaniging root
		if (node == root) 
			root = child;

		return child;
	}
	
	/*
	* remove a node from the tree
	* maintains this property of the tree:
	*     All nodes to the left will be less
	*     All nodes to the right will be greater
	*
	*/
	void remove(const KeyComparable & key, BinaryNode *& t)	{
		// stub function
	}

	/*
	* Finds the node with the smallest element in the subtree
	*
	*/
	BinaryNode * findMin(BinaryNode *t) const {
		return nullptr;
	}

	/*
	* Finds the node with the largest element in the subtree
	*
	*/
	BinaryNode * findMax(BinaryNode *t) const {
		// add needed code
	}

	/*
	* Finds the node with that satisfies equality for the element
	*
	*/
	BinaryNode *  find(const KeyComparable & key, BinaryNode *node) const {
		// stub function
		return nullptr;
	}

	/*
	* Returns true if the item is found in the tree
	*
	*/
	bool contains(const Value & item, BinaryNode *t) const 	{
		// stub function
		return false;
	}

	/*
	* Removes all elelements from the tree
	*
	*/
	void makeEmpty(BinaryNode * & t) {
		// stub function
	}

	/*
	* Prints the inorder the tree to the stream out
	*
	*/
	void printTree(BinaryNode *t, std::ostream & out) const {

		if (t == nullptr) {
			return;
		}

		printTree(t->left, out);

		out << "Printing: " << *t->value << endl;

		int height = nodeHeightPrint(t);
		int bf = balanceFactorPrint(t);

		out << "Height: " << height << " Balance Factor: " << bf << endl;

		printTree(t->right, out);
	}
	
public:
	BinarySearchTree()	{
		// stub function
	};
	
	~BinarySearchTree()	{
		// stub function
	};
	/*
	* Finds the node with the smallest element in the tree
	*
	*/
	const Value findMin() const	{
		// stub function
		return nullptr;
	}

	/*
	* Finds the node with the largest element in the tree
	*
	*/
	const Value findMax() const	{
		// stub function
		return nullptr;
	}

	/*
	* Finds the node with that the key
	* updates the founditem refrerence if found
	* returns true if it was found 
	* returns false if it was not 
	*
	*/
	bool find(const KeyComparable & key , Value & foundItem) const 	{
		// stub function
		return false;
	}

	/*
	* Returns true if the item is found in the tree
	*
	*/
	bool contains(const KeyComparable & key) const {
		// stub code 
		return false;
	};

	/*
	* Returns true if tree has no nodes
	*
	*/
	bool isEmpty() const  {
		// stub code 
		return root == NULL;
	}

	/*
	* Prints the inorder the tree to the stream out
	*
	*/
	void printTree(std::ostream & out = cout) const {
		printTree(root , out);
	}

	/*
	* Removes all nodes from the tree
	*
	*/
	void makeEmpty()
	{
		// stub function
	};
	
	/*
	* Inserts a node into the tree
	* maintains this property of the tree:
	*     All nodes to the left will be less
	*     All nodes to the right will be greater
	*
	*/
	bool insert( Value value,  KeyComparable key) {
		
		BinaryNode* temp = insert(value, key, root);

		if (temp != nullptr)
			return true;
		else
			return false; 
	}

	/*
	* Removes the nodes if it contains the given item
	*
	*/
	void remove(const KeyComparable & key) {
		// stub function		
	}
	
};

//Output
/*
Printing: (Ada Lovelace, id: 30, speciality: Programming)
Height: 0 Balance Factor: 0
Printing: (Grace Hopper, id: 40, speciality: Compilers)
Height: 1 Balance Factor: 0
Printing: (John von Neumann, id: 45, speciality: Hardware)
Height: 0 Balance Factor: 0
Printing: (Robert Ward, id: 50, speciality: Education)
Height: 2 Balance Factor: 0
Printing: (Your Name, id: 51, speciality: Skynet)
Height: 1 Balance Factor: -1
Printing: (Thing Two, id: 52, speciality: AI)
Height: 0 Balance Factor: 0
Printing: (Lonnie Heinke, id: 53, speciality: Education)
Height: 3 Balance Factor: 0
Printing: (Thing One, id: 54, speciality: Education)
Height: 0 Balance Factor: 0
Printing: (Dennis Ritchie, id: 55, speciality: Compilers)
Height: 2 Balance Factor: -1
Printing: (Alan Turing, id: 60, speciality: Cryptogarphy)
Height: 0 Balance Factor: 0
Printing: (Ken Thompson, id: 70, speciality: OS)
Height: 1 Balance Factor: 0
Printing: (Edsger Dikstra, id: 80, speciality: Algorithms)
Height: 0 Balance Factor: 0
Press any key to continue . . .
*/