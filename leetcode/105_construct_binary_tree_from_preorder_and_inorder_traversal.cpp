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
    TreeNode *buildTree(vector<int> &preorder, int s1, int e1, 
                        vector<int> &inorder, int s2, int e2) {
        if (s1 > e1) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[s1]);
        if (s1 == e1) {
            return root;
        }
        int i;
        for (i = s2; i <= e2; i++) {
            if (inorder[i] == root->val) {
                break;
            }
        }
        int left_len = i - s2;
        root->left = buildTree(preorder, s1+1, s1+left_len, inorder, s2, i-1);
        root->right = buildTree(preorder, s1+left_len+1, e1, inorder, i+1, e2);
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size());
    }
};
