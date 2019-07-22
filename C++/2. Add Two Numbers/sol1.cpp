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
        ListNode *head = new ListNode(0);
        ListNode *result = head;
        int carry = 0;
        while (l1 && l2) {
            int add = l1->val + l2->val + carry;
            ListNode *node = new ListNode(add % 10);
            //node->val = add % 10;
            carry = add / 10;
            l1 = l1->next;
            l2 = l2->next;
            result->next = node;
            result = result->next;
        }
        while (l1) {
            int add = l1->val + carry;
            ListNode *node = new ListNode(add % 10);
            carry = add / 10;
            l1 = l1->next;
            result->next = node;
            result = result->next;
        }
        while (l2) {
            int add = l2->val + carry;
            ListNode *node = new ListNode(add % 10);
            carry = add / 10;
            l2 = l2->next;
            result->next = node;
            result = result->next;
        }
        if (carry) {
            ListNode *node = new ListNode(carry);
            result->next = node;
        }
        
        return head->next;
    }
};