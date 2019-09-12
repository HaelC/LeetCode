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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* node;
        if (!l1)
            return l2;
        else if (!l2)
            return l1;
        else {
            if (l1->val <= l2->val) {
                node = l1;
                node->next = mergeTwoLists(l1->next, l2);
            }
            else {
                node = l2;
                node->next = mergeTwoLists(l1, l2->next);
            }
        }
        return node;
    }
};