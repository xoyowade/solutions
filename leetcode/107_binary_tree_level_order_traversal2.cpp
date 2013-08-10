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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        stack<vector<int> > sres;
        vector<int> line;
        
        queue<TreeNode *> q;
        q.push(root);
        int count = q.size();
        while (!q.empty()) {
            if (count == 0) {
                sres.push(line);
                count = q.size();
                line.clear();
            }
            count--;
            
            TreeNode *n = q.front();
            q.pop();
            if (n) {
                line.push_back(n->val);
                q.push(n->left);
                q.push(n->right);
            }
        }
        while (!sres.empty()) {
            res.push_back(sres.top());
            sres.pop();
        }
        return res;
    }
};
