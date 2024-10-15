#include<iostream>

using namespace std;

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode() :data{ 0 }, left{ nullptr }, right{ nullptr } {};
	TreeNode(int val) : data{ val }, left{ nullptr }, right{ nullptr } {};
	TreeNode(int val, TreeNode* left, TreeNode* right) :data(val), left(left), right(right) {};
};

//create the node
TreeNode* createNode(int data) {
	TreeNode* curr = new TreeNode(data);
	return curr;
}

//In Order Traversal with recursion
void inOrderTraversal(TreeNode* root) {
	if (root) {
		inOrderTraversal(root->left);
		std::cout << root->data << "\t";
		inOrderTraversal(root->right);
	}
}