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
    TreeNode *buildTree(vector<int> &inorder, int s1, int e1, 
                        vector<int> &postorder, int s2, int e2) {
        if (e1 < s1) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[e2]);
        if (s2 == e2) {
            return root;
        }
        
        int i;
        for (i = s1; i <= e1; i++) {
            if (inorder[i] == root->val) {
                break;
            }
        }
        int left_len = i-s1;
        root->left = buildTree(inorder, s1, i-1, postorder, s2, s2+left_len-1);
        root->right = buildTree(inorder, i+1, e1, postorder, s2+left_len, e2-1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
