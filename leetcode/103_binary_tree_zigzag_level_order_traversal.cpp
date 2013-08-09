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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<TreeNode *> cur;
        stack<TreeNode *> next;
        cur.push(root);
        
        vector<vector<int> > res;
        vector<int> level;
        
        int count = cur.size();
        bool zig = true;
        while (!cur.empty() || !next.empty()) {
            if (count == 0) {
                // new level
                res.push_back(level);
                level.clear();
                count = next.size();
                cur.swap(next);
                zig = !zig;
            }
            count--;
            
            TreeNode *n = cur.top();
            cur.pop();
            
            if (n) {
                level.push_back(n->val);
                if (zig) {
                    next.push(n->left);
                    next.push(n->right);
                } else {
                    next.push(n->right);
                    next.push(n->left);
                }
            }
        }
        
        return res;
    }
};
