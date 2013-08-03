class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode *head;
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        
        head->next = mergeTwoLists(l1, l2);
        
        return head;
    }
};
