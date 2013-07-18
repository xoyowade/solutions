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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head || !head->next) {
            return head;
        }
        ListNode* new_head = head->next;
        ListNode* old_tail = new_head->next;
        new_head->next = head;
        head->next = old_tail;
        head = new_head;
        
        ListNode* node = head->next;
        
        while (true) {
            if (node->next && node->next->next) {
                ListNode* l = node->next;
                ListNode* r = l->next;
                ListNode* tail = r->next;
                node->next = r;
                r->next = l;
                l->next = tail;
                node = l;
            } else {
                return head;
            }
        }
    }
};
