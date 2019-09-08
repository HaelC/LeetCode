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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode* next = head->next;
        
        head->next = next->next;
        next->next = head;
        head = next;
        
        head->next->next = swapPairs(head->next->next);
        return head;
    }
};