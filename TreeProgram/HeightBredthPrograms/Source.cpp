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

//Get the height of BT using recurssion
//DFS Depth First Search
int heightOfBT(TreeNode* root) {
	int leftHeight{}, rightHeight{};
	if (!root)
		return 0;
	else {
		leftHeight = heightOfBT(root->left);
		rightHeight = heightOfBT(root->right);

		if (leftHeight > rightHeight)
			return (leftHeight + 1);
		else
			return (rightHeight + 1);
	}
}

//Get the height of BT without recurssion
//BFS Bredth First Search
int heightOfBTWR(TreeNode* root) {
	if (!root)
		return 0;

	std::queue<TreeNode*> q;
	q.push(root);
	int height = 0;

	while (!q.empty()) {
		size_t levelSize = q.size();
		for (int i = 0; i < levelSize; ++i) {
			TreeNode* curr = q.front();
			q.pop();
			if (curr->left)
				q.push(curr->left);
			if (curr->right)
				q.push(curr->right);
		}
		++height;
	}

	return height;
}

//Get the height of BT without recurssion
//BFS
int heightOfBTWR2(TreeNode* root) {
	if (!root)
		return 0;

	int level{};
	std::queue<TreeNode*> q;

	q.push(root);
	q.push(nullptr);
	while (!q.empty()) {
		root = q.front();
		q.pop();
		if (root == nullptr) {
			if (!q.empty())
				q.push(nullptr);
			level++;
		}
		else {
			if(root->left)
				q.push(root->left);

			if (root->right)
				q.push(root->right);
		}
	}
	return level;
}

//Function to search the deepest node in BT
TreeNode* deepestNode(TreeNode* root) {
	TreeNode* temp = nullptr;
	queue<TreeNode*> q{};
	if (!root)
		return temp;

	q.push(root);

	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
	return temp;
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
	insertNodeToBT(&root, 34);

	printInLevelOredr(root);

	cout << "Height of BT : " << heightOfBT(root) << endl;
	cout << "Height of BTWR : " << heightOfBTWR(root) << endl;
	cout << "Height of BTWR2 : " << heightOfBTWR2(root) << endl;

	cout << "Deepest node of BT : " << deepestNode(root)->data << endl;

	return 0;
}