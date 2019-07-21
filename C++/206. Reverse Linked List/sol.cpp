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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* oldHead = head;
        while (temp && temp->next) {
            head = temp->next;
            temp->next = temp->next->next;
            head->next = oldHead;
            oldHead = head;
        }
        return head;
    }
};