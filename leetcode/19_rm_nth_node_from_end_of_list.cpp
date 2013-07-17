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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p = head;
        int len = 0;
        while(p) {
            len++;
            p = p->next;
        }
        if (n == len) {
            return head->next;
        }
        p = head;
        for (int i = 0; i < len - n - 1; i++) {
            p = p->next;
        }
        p->next = p->next->next;
        return head;
    }
};
