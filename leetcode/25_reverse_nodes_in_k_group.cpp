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
    ListNode *reverseKGroup(ListNode *head, int k, bool recursive) {
        if (k <= 1 || !head) {
            return head;
        }
        int count = k;
        ListNode *node = head;
        while (node && count > 1) {
            node = node->next;
            count--;
        }
        if (count > 1 || !node) {
            return head;
        }
        
        ListNode *tail = node->next;
        node->next = reverseKGroup(head, k-1, false);
        ListNode *reverse_tail = node->next;
        for (int i = 1; i < k-1; i++) {
            reverse_tail = reverse_tail->next;
        }
        reverse_tail->next = tail;
        head = node;
        
        if (recursive) {
            reverse_tail->next = reverseKGroup(reverse_tail->next, k, true);
        }
        return head;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return reverseKGroup(head, k, true);
    }
};
