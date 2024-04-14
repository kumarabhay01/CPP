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

int calculateSize(TreeNode* root) {
	if (!root)
		return 0;
	return (calculateSize(root->left) + 1 + calculateSize(root->right));
}

//use level order for non recursive function
static int calculateSizeWR(TreeNode* root) {
	int size{};
	TreeNode* temp{};
	queue<TreeNode*> que;
	if (!root)
		return size;
	else
		que.push(root);
	while (!que.empty()) {
		temp = que.front();
		size += 1;
		que.pop();
		if (temp->left)
			que.push(temp->left);
		if (temp->right)
			que.push(temp->right);
	}
	return size;
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

	cout << "Size : " << calculateSize(root) << endl;
	cout << "Size : " << calculateSizeWR(root) << endl;

	return 0;
}