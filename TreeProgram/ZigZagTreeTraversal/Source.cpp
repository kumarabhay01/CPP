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

void printInLevelOrder(TreeNode* root) {
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

void zigZagTraversal(TreeNode* root) {
	TreeNode* curr{};
	int leftToRight = 1;
	if (!root)
		return;

	queue<TreeNode*> currentLevel;
	stack<TreeNode*> nextLevel;
	currentLevel.push(root);
	while (!currentLevel.empty()) {
		curr = currentLevel.front();
		currentLevel.pop();
		if (curr) {
			cout << curr->data << "\t";
			if (leftToRight) {
				if (curr->left)
					nextLevel.push(curr->left);
				if (curr->right)
					nextLevel.push(curr->right);
			}
			else {
				if (curr->right)
					nextLevel.push(curr->right);
				if (curr->left)
					nextLevel.push(curr->left);
			}
		}
		if (currentLevel.empty() && !nextLevel.empty()) {
			leftToRight = 1 - leftToRight;
			while (!nextLevel.empty()) {
				currentLevel.push(nextLevel.top());
				nextLevel.pop();
			}
		}
	}
}



int main() {
	TreeNode* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	printInLevelOrder(root);

	zigZagTraversal(root);

	return 0;
}