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

bool isCompleteBT(TreeNode* root) {
	if (!root)
		return true;

	TreeNode* curr, * r;
	queue<TreeNode*> que{};

	que.push(root);
	int count = 0;
	while (!que.empty()) {
		int size = static_cast<int>(que.size());
		for (int idx = 0; idx < size; idx++) {
			curr = que.front();
			que.pop();
			if (curr == nullptr) {
				count++;
				while (!que.empty()) {
					r = que.front();
					que.pop();
					if (r != nullptr)
						return false;
				}
				break;
			}
			que.push(curr->left);
			que.push(curr->right);
		}
	}
	return true;
}

int main() {
	TreeNode* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	printInLevelOrder(root);

	cout << isCompleteBT(root);
	return 0;
}