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
    ListNode* removeElements(ListNode* head, int val) {     
        while (head && head->val == val) {
            head = head->next;
        }
        
        if (!head)
            return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast) {
            while (fast && fast->val == val) {
                fast = fast->next;
            }
            slow->next = fast;
            slow = slow->next;
            if (fast)
                fast = fast->next;
        }
        /*
        if (fast && fast->val == val) {
            slow->next = nullptr;
        }
        */
        return head;
    }
};