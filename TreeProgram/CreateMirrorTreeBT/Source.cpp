#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) :data(val), left(nullptr), right(nullptr) {};
};

//create the node
TreeNode* createNode(int data) {
	TreeNode* curr = new TreeNode(data);
	return curr;
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

//Ceate Mirrorof the tree
TreeNode* createMirrorTree(TreeNode* root) {
	TreeNode* temp{};
	if (root) {
		createMirrorTree(root->left);
		createMirrorTree(root->right);

		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
	return root;
}

int main() {
	TreeNode* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);

	printInLevelOredr(root);
	TreeNode* tree2 = createMirrorTree(root);
	printInLevelOredr(tree2);

	return 0;
}