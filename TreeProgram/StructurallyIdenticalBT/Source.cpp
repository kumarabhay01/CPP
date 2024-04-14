#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool areStructurallyIdenticalWR(TreeNode* tree1, TreeNode* tree2) {
    stack<pair<TreeNode*, TreeNode*>> s;
    s.push({ tree1, tree2 });

    while (!s.empty()) {
        TreeNode* node1 = s.top().first;
        TreeNode* node2 = s.top().second;
        s.pop();

        if (!node1 && !node2) {
            continue;
        }

        if (!node1 || !node2) {
            return false;
        }

        if (node1->data != node2->data) {
            return false;
        }

        s.push({ node1->left, node2->left });
        s.push({ node1->right, node2->right });
    }

    return true;
}

bool areStructurallyIdentical(TreeNode* tree1, TreeNode* tree2) {
    if (!tree1 && !tree2) {
        return true;
    }

    if (!tree1 || !tree2) {
        return false;
    }

    return (tree1->data == tree2->data && areStructurallyIdentical(tree1->left, tree2->left) &&
        areStructurallyIdentical(tree1->right, tree2->right));
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);

    if (areStructurallyIdenticalWR(root1, root2)) {
        cout << "Both trees are structurally identical." << endl;
    }
    else {
        cout << "Trees are not identical." << endl;
    }

    if (areStructurallyIdentical(root1, root2)) {
        cout << "Both trees are structurally identical." << endl;
    }
    else {
        cout << "Trees are not identical." << endl;
    }

    // Clean up memory (optional)
    delete root1;
    delete root2;

    return 0;
}
