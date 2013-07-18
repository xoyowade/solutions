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
    void addListToTail(ListNode* list, ListNode* tail_list) {
        while(tail_list) {
            list->next = tail_list;
            list = list->next;
            tail_list = tail_list->next;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (lists.size() == 0) {
            return NULL;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        ListNode* l = lists.back();
        lists.pop_back();
        ListNode* r = mergeKLists(lists);
        
        ListNode head(0);
        ListNode* list = &head;
        while(l && r) {
            if (l->val < r->val) {
                list->next = l;
                l = l->next;
            } else {
                list->next = r;
                r = r->next;
            }
            list = list->next;
        }
        if(l) {
            addListToTail(list, l);
        } else if (r) {
            addListToTail(list, r);
        }
        
        return head.next;
    }
};
