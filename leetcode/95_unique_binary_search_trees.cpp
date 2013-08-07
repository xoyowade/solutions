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
    vector<TreeNode *> generateTrees(int l, int r) {
        vector<TreeNode *> res;
        TreeNode *root = NULL;
        if (l > r) {
            res.push_back(root);
            return res;
        }
        if (l == r) {
            root = new TreeNode(l);
            res.push_back(root);
            return res;
        }
        for (int i = l; i <= r; i++) {
            const vector<TreeNode *> &left = generateTrees(l, i-1);
            const vector<TreeNode *> &right = generateTrees(i+1, r);
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return generateTrees(1, n);
    }
};
