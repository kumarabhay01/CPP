#include<iostream>
#include<stack>
#include<queue>

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

//Pre Order Traversal in recursion
void preOrderTraversal(TreeNode* root) {
	if (root) {
		std::cout << root->data << "\t";
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
}

//Pre Order Traversal without recursion
void nonRecursivePreorderTraversal(TreeNode* root) {
	std::stack<TreeNode*> stk;
	while (1) {
		while (root) {
			std::cout << root->data << "\t";
			stk.push(root);
			root = root->left;
		}
		if (stk.empty())
			break;
		root = stk.top();
		stk.pop();
		root = root->right;
	}
}

//In Order Traversal with recursion
void inOrderTraversal(TreeNode* root) {
	if (root) {
		inOrderTraversal(root->left);
		std::cout << root->data << "\t";
		inOrderTraversal(root->right);
	}
}

//In Order Traversal without recursion
void nonRecursiveInorderTraversal(TreeNode* root) {
	std::stack<TreeNode*> stk;
	while (1) {
		while (root) {
			stk.push(root);
			root = root->left;
		}
		if (stk.empty())
			break;
		root = stk.top();
		std::cout << root->data << "\t";
		stk.pop();
		root = root->right;
	}
}

//Post Order Traversal with recursion
void postOrderTraversal(TreeNode* root) {
	if (root) {
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		std::cout << root->data << "\t";
	}
}

// Postorder traversal without recursion
void postorderIterative(TreeNode* root) {
	if (!root)
		return;

	std::stack<TreeNode*> s1, s2;
	s1.push(root);

	while (!s1.empty()) {
		TreeNode* curr = s1.top();
		s1.pop();
		s2.push(curr);

		if (curr->left)
			s1.push(curr->left);
		if (curr->right)
			s1.push(curr->right);
	}

	// Print the postorder traversal
	while (!s2.empty()) {
		std::cout << s2.top()->data << " ";
		s2.pop();
	}
}

// Postorder traversal without recursion (optimized)
void postorderIterativeOptimized(TreeNode* root) {
	if (!root)
		return;

	std::stack<TreeNode*> s;
	TreeNode* curr = root;
	TreeNode* prev = nullptr;

	while (curr || !s.empty()) {
		if (curr) {
			s.push(curr);
			curr = curr->left;
		} 
		else {
			TreeNode* topNode = s.top();
			if (topNode->right && topNode->right != prev) {
				curr = topNode->right;
			}
			else {
				std::cout << topNode->data << " ";
				prev = topNode;
				s.pop();
			}
		}
	}
}

void levelOrderTraversal(TreeNode* root) {
	if (!root)
		return;

	std::queue<TreeNode*> que;
	que.push(root);

	while (!que.empty()) {
		TreeNode* curr = que.front();
		que.pop();
		std::cout << curr->data << "\t";
		if (curr->left)
			que.push(curr->left);
		if (curr->right)
			que.push(curr->right);
	}

}

int main() {
	TreeNode* root = createNode(5);

	root->left = createNode(1);
	root->right = createNode(4);
	root->left->left = createNode(3);
	root->left->right = createNode(8);
	root->right->left = createNode(7);
	root->right->right = createNode(9);

	preOrderTraversal(root);
	std::cout << std::endl;
	nonRecursivePreorderTraversal(root);
	std::cout << std::endl;
	inOrderTraversal(root);
	std::cout << std::endl;
	nonRecursiveInorderTraversal(root);
	std::cout << std::endl;
	postOrderTraversal(root);
	std::cout << std::endl;
	levelOrderTraversal(root);

	return 0;
}
