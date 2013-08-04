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
        
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *l = &dummy;
        while (l->next && l->next->next) {
            if (l->next->val != l->next->next->val) {
                l = l->next;
            } else {
                ListNode *next = l->next;
                while (next->next && next->val == next->next->val) {
                    next = next->next;
                }
                l->next = next->next;
            }
        }
        
        return dummy.next;
    }
};
