#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) : data{ val }, left{ nullptr }, right{ nullptr } {};
};

struct qItem {
	TreeNode* node;
	int depth;
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

int minimumDepthOfBT_1(TreeNode* root) {
	//If root is NULL Depth = 0
	if (!root)
		return 0;

	//If root leave node depth = 1
	if (!root->left && !root->right)
		return 1;

	if (!root->left)
		return minimumDepthOfBT_1(root->right) + 1;

	if(!root->right)
		return minimumDepthOfBT_1(root->left) + 1;

	return min(minimumDepthOfBT_1(root->left), minimumDepthOfBT_1(root->right)) + 1;
}

int minimumDepthOfBT_2(TreeNode* root) {
	if (!root)
		return 0;
	if (!root->left || !root->right)
		return (minimumDepthOfBT_2(root->left) + minimumDepthOfBT_2(root->right) + 1);
	int leftMin = minimumDepthOfBT_2(root->left);
	int rightMin = minimumDepthOfBT_2(root->right);
	return (leftMin < rightMin ? leftMin : rightMin);
}

int minimumDepthOfBT_3(TreeNode* root) {
	if (root == nullptr)
		return 0;

	queue<qItem> q;
	qItem qi = { root, 1 };
	q.push(qi);

	while (!q.empty()) {
		qi = q.front();
		q.pop();
		TreeNode* node = qi.node;
		int depth = qi.depth;

		if (node->left == nullptr && node->right == nullptr)
			return depth;

		if (node->left != nullptr) {
			qi.node = node->left;
			qi.depth = depth + 1;
			q.push(qi);
		}

		if (node->left != nullptr) {
			qi.node = node->right;
			qi.depth = depth + 1;
			q.push(qi);
		}
	}
	return 0; // This line is not reachable but added for completeness
}


int main() {
	TreeNode* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	printInLevelOrder(root);
	cout << "Minimum Depth of BT 1: " << minimumDepthOfBT_1(root);
	cout << endl;
	cout << "Minimum Depth of BT 3: " << minimumDepthOfBT_3(root);
	return 0;
}