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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        int carry = 0;
        while (p1 && p2) {
            int val = p1->val + p2->val + carry;
            ListNode* node = new ListNode(val % 10);
            carry = val / 10;
            p1 = p1->next;
            p2 = p2->next;
            curr->next = node;
            curr = curr->next;
        }
        
        while (p1) {
            int val = p1->val + carry;
            ListNode* node = new ListNode(val % 10);
            carry = val / 10;
            p1 = p1->next;
            curr->next = node;
            curr = curr->next;
        }
        
        while (p2) {
            int val = p2->val + carry;
            ListNode* node = new ListNode(val % 10);
            carry = val / 10;
            p2 = p2->next;
            curr->next = node;
            curr = curr->next;
        }
        
        if (carry) {
            ListNode* node = new ListNode(1);
            curr->next = node;
            curr = curr->next;
        }
        
        return head->next;
    }
};