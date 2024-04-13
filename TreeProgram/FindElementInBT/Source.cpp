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

bool searchUsingLevelOrder(TreeNode* root, int data) {
	TreeNode* temp{};
	queue<TreeNode*> que;

	if (root)
		que.push(root);

	while (!que.empty()) {
		temp = que.front();
		if (temp->data == data)
			return true;
		else {
			que.pop();
			if (temp->left)
				que.push(temp->left);
			if(temp->right)
				que.push(temp->right);
		}
	}
		
	return false;
}

int main() {
	TreeNode* root = createNode(5);

	root->left = createNode(89);
	root->right = createNode(4);
	root->left->left = createNode(45);
	root->left->right = createNode(32);
	root->right->left = createNode(7);
	root->right->right = createNode(4);

	cout << "searchUsingLevelOrder() : " << searchUsingLevelOrder(root, 7) << endl;
	cout << "searchUsingLevelOrder() : " << searchUsingLevelOrder(root, 8) << endl;

	return 0;
}
