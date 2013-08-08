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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *first = NULL, *second = NULL;
        TreeNode *cur = root, *prev = NULL;
        stack<TreeNode *> s;
        bool done = false;
        while (!s.empty() || cur) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                // handle cur
                if (prev && prev->val > cur->val) {
                    if (!first) {
                        first = prev;
                        second = cur;
                    } else {
                        second = cur;
                        break;  
                    }
                }
                prev = cur;
                cur = cur->right;
            }
        }
        
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};
