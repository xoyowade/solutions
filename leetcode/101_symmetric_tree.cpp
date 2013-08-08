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
    bool isSymmetric(TreeNode *n1, TreeNode *n2) {
        if (!n1 && !n2) {
            return true;
        }
        if ((!n1 && n2) || (n1 && !n2)) {
            return false;
        }
        if (n1->val != n2->val) {
            return false;
        }
        if (!isSymmetric(n1->left, n2->right)) {
            return false;
        }
        if (!isSymmetric(n1->right, n2->left)) {
            return false;
        }
        return true;
    }
    bool isSymmetric_recursive(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) {
            return true;
        }
        
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) {
            return true;
        }
        
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        s1.push(root->left);
        s2.push(root->right);
        while (!s1.empty() && !s2.empty()) {
            TreeNode *n1 = s1.top();
            TreeNode *n2 = s2.top();
            s1.pop();
            s2.pop();
            
            if ((n1 && !n2) || (!n1 && n2)) {
                return false;
            }
            if (n1 && n2) {
                if (n1->val != n2->val) {
                    return false;
                }
                s1.push(n1->left);
                s1.push(n1->right);
                s2.push(n2->right);
                s2.push(n2->left);
            }
        }
        
        return s1.empty() && s2.empty();
    }
};
