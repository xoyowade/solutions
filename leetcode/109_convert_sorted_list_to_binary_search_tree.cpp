/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *&list, int s, int e) {
        if (s > e) {
            return NULL;
        }
        int mid = s + (e-s)/2;
        TreeNode *left = sortedListToBST(list, s, mid-1);
        TreeNode *root = new TreeNode(list->val);
        list = list->next;
        root->left = left;
        root->right = sortedListToBST(list, mid+1, e);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = 0;
        ListNode *cur = head;
        while (cur) {
            len++;
            cur = cur->next;
        }
        return sortedListToBST(head, 0, len-1);
    }
};
