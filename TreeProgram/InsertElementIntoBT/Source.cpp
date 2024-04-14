#include<iostream>
#include<queue>
#include<stack>

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

void insertNodeToBT(TreeNode** root,int data) {
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

int main() {
	TreeNode* root{};

	insertNodeToBT(&root, 8);
	printInLevelOredr(root);

	insertNodeToBT(&root, 7);
	printInLevelOredr(root);

	insertNodeToBT(&root, 9);
	printInLevelOredr(root);

	insertNodeToBT(&root, 10);
	printInLevelOredr(root);

	return 0;
}