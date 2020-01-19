/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// reference: https://leetcode.com/problems/sort-list/discuss/46712/Bottom-to-up(not-recurring)-with-o(1)-space-complextity-and-o(nlgn)-time-complextity
class Solution {
private:
    ListNode* split(ListNode* node, int step) {
        for (int i = 1; node && i < step; i++) {
            node = node->next;
        }
        if (!node) {
            return NULL;
        }
        ListNode* second = node->next;
        node->next = NULL;
        return second;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head) {
        ListNode* cur = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        cur->next = l1 ? l1 : l2;
        while (cur->next) {
            cur = cur->next;
        }
        return cur;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        
        ListNode* temp = head;
        int length = 0;
        while (temp) {
            length++;
            temp = temp->next;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *left, *right, *tail;
        for (int step = 1; step < length; step *= 2) {
            temp = dummy->next;
            tail = dummy;
            while (temp) {
                left = temp;
                right = split(left, step);
                temp = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        return dummy->next;
    }
};