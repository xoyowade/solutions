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
    TreeNode *sortedArrayToBST(vector<int> &num, int s, int e) {
        if (s > e) {
            return NULL;
        }
        int mid = (s+e)/2;
        TreeNode *root = new TreeNode(num[mid]);
        if (s == e) {
            return root;
        }
        root->left = sortedArrayToBST(num, s, mid-1);
        root->right = sortedArrayToBST(num, mid+1, e);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return sortedArrayToBST(num, 0, num.size()-1);
    }
};
