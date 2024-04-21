#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printVector(const std::vector<int>& path) {
    for (int val : path) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

void printArray(int ints[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        cout << ints[i] << " ";
    }
    cout << endl;
}

//Print Path Using Vector
void printPathsRecurVector(TreeNode* node, std::vector<int>& path) {
    if (!node)
        return;

    // Append the current node's value to the path
    path.push_back(node->val);

    // If it's a leaf node, print the path
    if (!node->left && !node->right) {
        printVector(path);
    }
    else {
        // Otherwise, explore both subtrees
        printPathsRecurVector(node->left, path);
        printPathsRecurVector(node->right, path);
    }

    // Remove the current node from the path (backtrack)
    path.pop_back();
}

//Print Path Using Array
void printPathsRecurArray(TreeNode* node, int path[], int pathLen)
{
    if (node == NULL)
        return;

    /* append this node to the path array */
    path[pathLen] = node->val;
    pathLen++;

    /* it's a leaf, so print the path that lead to here */
    if (node->left == NULL && node->right == NULL)
    {
        printArray(path, pathLen);
    }
    else
    {
        /* otherwise try both subtrees */
        printPathsRecurArray(node->left, path, pathLen);
        printPathsRecurArray(node->right, path, pathLen);
    }
}

//Delete Binary Tree
void deleteBT(TreeNode* root) {
    if (!root)
        return;

    deleteBT(root->left);
    deleteBT(root->right);
    delete(root);
}

int main() {
    
    //Create Tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);

    std::vector<int> path;
    std::cout << "Root-to-leaf paths:\n";
    printPathsRecurVector(root, path);

    int pathArray[1000];
    printPathsRecurArray(root, pathArray, 0);

    deleteBT(root);
    return 0;
}
