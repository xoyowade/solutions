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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (k == 0 || !head) {
            return head;
        }
        int len = 0;
        ListNode *tail = NULL;
        ListNode *node = head;
        while (node) {
            len++;
            tail = node;
            node = node->next;
        }
        k = k % len;
        if (k == 0) {
            return head;
        }
        
        int count = 1;
        ListNode *cut = head;
        while (count < len - k) {
            cut = cut->next;
            count++;
        }
        
        ListNode *newHead = cut->next;
        tail->next = head;
        cut->next = NULL;
        
        return newHead;
    }
};
