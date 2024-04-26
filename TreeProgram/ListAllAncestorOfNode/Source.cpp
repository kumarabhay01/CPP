#include<iostream>
#include<queue>

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

int printAllAncestors(TreeNode* root, TreeNode* node) {
	if (root == nullptr)
		return 0;

	if (root->left == node || root->right == node ||
		printAllAncestors(root->left, node) || printAllAncestors(root->right, node)) {
		cout << root->data <<"\t";
		return 1;
	}
	return 0;
}

int main() {
	TreeNode* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	root->right->right->left = createNode(8);
	printInLevelOrder(root);

	printAllAncestors(root, root->right->right->left);
	return 0;
}