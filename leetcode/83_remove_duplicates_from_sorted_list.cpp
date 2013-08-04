/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head || !head->next) {
            return head;
        }
        
        ListNode *l = head;
        while (l->next) {
            if (l->next->val == l->val) {
                l->next = l->next->next;
            } else {
                l = l->next;
            }
        }
        return head;
    }
};
