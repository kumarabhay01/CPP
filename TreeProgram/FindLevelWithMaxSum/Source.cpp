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

//Find Level Will Max Sum
int findMaxSumInLevel(TreeNode* root, int& sum) {
	int height{}, level{};
	
	queue<TreeNode*> que;
	if (root)
		que.push(root);

	while (!que.empty()) {
		int LevelSum{};
		size_t len = que.size();
		for (int i = 0; i < len; ++i) {
			TreeNode* curr = que.front();
			que.pop();
			LevelSum += curr->data;

			if (curr->left)
				que.push(curr->left);

			if (curr->right)
				que.push(curr->right);
		}
		++height;
		if (LevelSum > sum) {
			sum = LevelSum;
			level = height;
		}
	}
	return level;
}

//Find Sum of all the element in the tree
int findSumofAllTheElement(TreeNode* root) {
	int sum{};
	queue<TreeNode*> que;
	if (root)
		que.push(root);

	while (!que.empty()) {
		TreeNode* curr = que.front();
		que.pop();
		sum += curr->data;
		if (curr->left)
			que.push(curr->left);
		if (curr->right)
			que.push(curr->right);
	}
	return sum;
}

int main() {
	TreeNode* root{};
	int sum{}, maxLevel{};

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

	maxLevel = findMaxSumInLevel(root, sum);

	cout << "Level with max sum is: " << maxLevel << "\n" << "Sum is: " << sum << endl;
	cout << "Sum of all the element: " << findSumofAllTheElement(root) << endl;

	return 0;
}