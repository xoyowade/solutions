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
    void dfs(TreeNode *root, int num) {
        num = num*10 + root->val;
        if (!root->left && !root->right) {
            nums.push_back(num);
            return;
        }
        
        if (root->left) {
            dfs(root->left, num);
        }
        if (root->right) {
            dfs(root->right, num);
        }
    }
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        nums.clear();
        if (!root) {
            return 0;
        }
        
        dfs(root, 0);
        
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        return sum;
    }
    
    vector<int> nums;
};
