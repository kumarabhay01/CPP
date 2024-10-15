#include<iostream>
#include<stack>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  //create the node
  TreeNode* createNode(int data) {
      TreeNode* curr = new TreeNode(data);
      return curr;
  }


    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<TreeNode*> stk{};
        int sum{};
        while (1) {
            while (root) {
                stk.push(root);
                sum += root->val;
                root = root->left;
            }

            if (sum == targetSum)
                return true;

            if (stk.empty())
                break;

            root = stk.top();


            sum = sum - root->val;

            stk.pop();
            root = root->right;
        }
        return false;
    }

    bool hasPathSum2(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }

        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

        bool left_sum = hasPathSum(root->left, targetSum - root->val);
        bool right_sum = hasPathSum(root->right, targetSum - root->val);

        return left_sum || right_sum;
    }

    int main() {
        TreeNode* tree1 = createNode(5);
        tree1->left = createNode(4);
        tree1->right = createNode(8);
        tree1->left->left = createNode(11);
        tree1->left->left->left = createNode(7);
        tree1->left->left->right = createNode(2);
        tree1->right->left = createNode(13);
        tree1->right->right = createNode(4);
        tree1->right->right->right = createNode(1);

        cout << hasPathSum2(tree1, 22);

        return 0;
    }