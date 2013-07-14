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
    int len(const ListNode *l) {
        int len = 0;
        const ListNode *n = l;
        while(n) {
            len++;
            n = n->next;
        }
        return len;
    }
    
    int indentSum(int* sum) {
        if (*sum > 9) {
            *sum -= 10;
            return 1;
        }
        return 0;
    }
    
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int len1, int len2) {
        if (!l2) {
            return l1;
        }
        int indent = 0;
        int sum = 0;
        ListNode *l = new ListNode(0), *node = l;
        sum = l1->val + l2->val + indent;
        indent = indentSum(&sum);
        node->val = sum;
        
        for(int i = 1; i < len2; i++) {
            l1 = l1->next;
            l2 = l2->next;
            sum = l1->val + l2->val + indent;
            indent = indentSum(&sum);
            node->next = new ListNode(sum);
            
            node = node->next;
        }
        int diff_len = len1 - len2;
        if (diff_len > 0) {
            for(int i = 0; i < diff_len; i++) {
                l1 = l1->next;
                sum = l1->val + indent;
                indent = indentSum(&sum);
                node->next = new ListNode(sum);
                
                node = node->next;
            }
        }
        if (indent != 0) {
            node->next = new ListNode(indent);
        }
        return l;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = len(l1);
        int len2 = len(l2);
        if (len1 > len2) {
            return addTwoNumbers(l1, l2, len1, len2);
        } else {
            return addTwoNumbers(l2, l1, len2, len1);
        }
    }
};
