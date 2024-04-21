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

bool areMirror(TreeNode* tree1, TreeNode* tree2) {
	if (tree1 == nullptr && tree2 == nullptr)
		return true;
	if (tree1 == nullptr || tree2 == nullptr)
		return false;

	if (tree1->data != tree2->data)
		return false;
	else
		return (areMirror(tree1->left, tree2->right) && areMirror(tree1->right, tree2->left));
}

int main() {
	TreeNode* tree1 = createNode(1);
	tree1->left = createNode(2);
	tree1->right = createNode(3);
	tree1->left->left = createNode(4);
	tree1->left->right = createNode(5);
	cout << "Tree 1 is: \n";
	printInLevelOredr(tree1);

	TreeNode* tree2 = createNode(1);
	tree2->left = createNode(3);
	tree2->right = createNode(2);
	tree2->right->right = createNode(4);
	tree2->right->left = createNode(5);
	cout << "Tree 2 is: \n";
	printInLevelOredr(tree2);

	cout << areMirror(tree1, tree2);
	return 0;
}