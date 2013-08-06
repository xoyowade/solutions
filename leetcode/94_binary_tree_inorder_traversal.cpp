/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        stack<TreeNode *> nodes;
        if (root) {
            nodes.push(root);
        }
        while (!nodes.empty()) {
            TreeNode *node = nodes.top();
            nodes.pop();
            if (node->right) {
                nodes.push(node->right);
            }
            TreeNode *left = node->left;
            if (left) {
                node->right = NULL;
                node->left = NULL;
                nodes.push(node);
                nodes.push(left);
            } else {
                res.push_back(node->val);
            }
        }
        
        return res;
    }
};
