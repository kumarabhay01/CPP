#include<iostream>
#include<vector>
#include<queue>
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
 
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result{};
        vector<int> curr{};
        queue<TreeNode*> currLevel{};
        stack<TreeNode*> nextLevel{};
        TreeNode* currNode{};
        int leftToRight = 0;
        if (root == nullptr)
            return result;

        currLevel.push(root);
        while (!currLevel.empty()) {
            currNode = currLevel.front();
            currLevel.pop();
            if (currNode) {
                curr.push_back(currNode->val);
                cout << currNode->val << " ";
                if (leftToRight) {
                    if (currNode->right)
                        nextLevel.push(currNode->right);
                    if (currNode->left)
                        nextLevel.push(currNode->left);
                }
                else {
                    if (currNode->left)
                        nextLevel.push(currNode->left);
                    if (currNode->right)
                        nextLevel.push(currNode->right);
                }
            }
            if (currLevel.empty()) {
                result.push_back(curr);
                curr.clear();
            }
            if (currLevel.empty() && !nextLevel.empty()) {
                leftToRight = 1 - leftToRight;
                while (!nextLevel.empty()) {
                    currLevel.push(nextLevel.top());
                    nextLevel.pop();
                }
            }
        }

        return result;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if (root == NULL) return v;
        queue<TreeNode*>q;
        q.push(root);
        bool flag = false;
        while (!q.empty()) {
            vector<int>c;
            int l = q.size();
            for (int i = 0; i < l; i++) {
                TreeNode* temp = q.front(); q.pop();
                c.push_back(temp->val);
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);

            }
            if (flag) reverse(c.begin(), c.end());
            flag = !flag;
            v.push_back(c);
        }
        return v;
    }

    int main() {
        TreeNode* root = createNode(3);
        root->left = createNode(9);
        root->right = createNode(20);
        root->right->left = createNode(15);
        root->right->right = createNode(7);


        vector<vector<int>> result = zigzagLevelOrder(root);
        cout << "[";
        for (vector<int> vec : result) {
            cout << "[";
            for (int i : vec)
                cout << i << " ";
            cout << "]";
        }
        cout << "]";

        return 0;
    }