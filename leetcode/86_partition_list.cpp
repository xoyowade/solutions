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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode g_dummy(0);
        ListNode l_dummy(0);
        ListNode *g_tail = &g_dummy;
        ListNode *l_tail = &l_dummy;
        
        while (head) {
            if (head->val < x) {
                l_tail->next = head;
                l_tail = l_tail->next;
                head = head->next;
            } else {
                g_tail->next = head;
                g_tail = g_tail->next;
                head = head->next;
            }
        }
        
        g_tail->next = NULL;
        l_tail->next = g_dummy.next;
        
        return l_dummy.next;
    }
};
