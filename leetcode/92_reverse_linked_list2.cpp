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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == m) {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *first = &dummy;
        int start = m-1;
        while (start-- > 0) {
            first = first->next;
        }
        ListNode *rtail = first->next;
        ListNode *rhead = rtail;
        ListNode *cur = rhead->next;
        start = n-m;
        while (start-- > 0) {
            ListNode *new_cur = cur->next;
            cur->next = rhead;
            rhead = cur;
            cur = new_cur;
        }
        first->next = rhead;
        rtail->next = cur;
        
        return dummy.next;
    }
};
