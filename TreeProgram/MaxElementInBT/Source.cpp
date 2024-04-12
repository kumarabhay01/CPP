#include<iostream>
#include<queue>

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

//Find max without recursion
//Have used preorder for this case
int findMax(TreeNode* root) {
	int rootVal{}, left{}, right{}, max = INT_MIN;
	if (root != nullptr) {
		rootVal = root->data;
		left = findMax(root->left);
		right = findMax(root->right);

		if (left > right)
			max = left;
		else
			max = right;

		if (rootVal > max)
			max = rootVal;
	}
	return max;
}

//Find Max without recursion 
//Using level order for this case
int findMaxWR(TreeNode* root) {
	TreeNode* temp{};
	queue<TreeNode* > que;
	int max = INT_MIN;
	if (root != nullptr)
		que.push(root);

	while (!que.empty()) {
		temp = que.front();
		que.pop();

		if (max < temp->data)
			max = temp->data;

		if (temp->left)
			que.push(temp->left);
		if (temp->right)
			que.push(temp->right);
	}
	return max;
}

int main() {
	TreeNode* root = createNode(5);

	root->left = createNode(89);
	root->right = createNode(4);
	root->left->left = createNode(45);
	root->left->right = createNode(32);
	root->right->left = createNode(7);
	root->right->right = createNode(4);

	cout << "findMax() : " << findMax(root) << endl;
	cout << "findMaxWR() : " << findMaxWR(root) << endl;

	return 0;
}