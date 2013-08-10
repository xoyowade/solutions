/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    TreeLinkNode *firstAtLevel(TreeLinkNode *node, int level, bool left) {
        if (level == 0 || !node) {
            return node;
        }
        if (left) {
            TreeLinkNode *l = firstAtLevel(node->left, level-1, left);
            if (l) {
                return l;
            } else {
                return firstAtLevel(node->right, level-1, left);
            }
        } else {
            TreeLinkNode *r = firstAtLevel(node->right, level-1, left);
            if (r) {
                return r;
            } else {
                return firstAtLevel(node->left, level-1, left);
            } 
        }
    }
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) {
            return;
        }
        
        int level = 1;
        TreeLinkNode *left = root->left;
        TreeLinkNode *right = root->right;
        while (left && right) {
            left->next = right;
            left = firstAtLevel(root->left, level, false);
            right = firstAtLevel(root->right, level, true);
            level++;
        }
        
        connect(root->left);
        connect(root->right);
    }
};
