#include<iostream>
#include<queue>
#include<stack>

using namespace std;

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) : data{ val }, left{ nullptr }, right{ nullptr } {};
};

//create the node
TreeNode* createNode(int data) {
	TreeNode* curr = new TreeNode(data);
	return curr;
}

void insertNodeToBT(TreeNode** root, int data) {
	TreeNode* newNode = createNode(data);
	TreeNode* temp{};
	queue<TreeNode*> que;
	if (!newNode)
		return;

	if (!*root)
		*root = newNode;
	else
		que.push(*root);

	while (!que.empty()) {
		temp = que.front();
		que.pop();

		if (temp->left)
			que.push(temp->left);
		else {
			temp->left = newNode;
			return;
		}

		if (temp->right)
			que.push(temp->right);
		else {
			temp->right = newNode;
			return;
		}
	}
}

void printInLevelOredr(TreeNode* root) {
	TreeNode* temp{};
	queue<TreeNode*> que;

	if (!root)
		return;
	else
		que.push(root);

	while (!que.empty()) {
		temp = que.front();
		que.pop();
		cout << temp->data << "\t";

		if (temp->left)
			que.push(temp->left);

		if (temp->right)
			que.push(temp->right);
	}
	cout << endl;
}


//Count Number of leaf node
//Leaf node are the node without children
int noOfLeafNode(TreeNode* root) {
	int count{};
	TreeNode* curr{};
	queue<TreeNode*> que;
	if (root)
		que.push(root);

	while (!que.empty()) {
		curr = que.front();
		que.pop();

		if (!curr->left && !curr->right)
			count++;

		if (curr->left)
			que.push(curr->left);

		if (curr->right)
			que.push(curr->right);
	}
	return count;
}

//Count Number of full nodes
//Full nodes are the node with both children
int noOfFullNode(TreeNode* root) {
	int count{};
	TreeNode* curr{};
	queue<TreeNode*> que;
	if (root)
		que.push(root);

	while (!que.empty()) {
		curr = que.front();
		que.pop();

		if (curr->left && curr->right)
			count++;

		if (curr->left)
			que.push(curr->left);

		if (curr->right)
			que.push(curr->right);
	}
	return count;
}

//Count Number of half nodes
//Half nodes are the node with just one children
int noOfHalfNode(TreeNode* root) {
	int count{};
	TreeNode* curr{};
	queue<TreeNode*> que;
	if (root)
		que.push(root);

	while (!que.empty()) {
		curr = que.front();
		que.pop();

		if (!curr->left && curr->right || curr->left && !curr->right)
			count++;

		if (curr->left)
			que.push(curr->left);

		if (curr->right)
			que.push(curr->right);
	}
	return count;
}

int main() {
	TreeNode* root{};

	insertNodeToBT(&root, 8);
	insertNodeToBT(&root, 7);
	insertNodeToBT(&root, 9);
	insertNodeToBT(&root, 2);
	insertNodeToBT(&root, 5);
	insertNodeToBT(&root, 6);
	insertNodeToBT(&root, 3);
	insertNodeToBT(&root, 4);
	printInLevelOredr(root);

	cout << "Number of leaf node : " << noOfLeafNode(root) << endl;
	cout << "Number of full node : " << noOfFullNode(root) << endl;
	cout << "Number of Half node : " << noOfHalfNode(root) << endl;

	return 0;
}