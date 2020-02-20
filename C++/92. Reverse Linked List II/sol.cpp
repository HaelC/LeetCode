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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        for (int i = 1; i < m; i++) {
            prev = temp;
            temp = temp->next;
        }
        
        ListNode* cut = prev;
        ListNode* tempTail = temp;
        ListNode* next = NULL;
        
        for (int i = m; i <= n; i++) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        
        if (cut) {
            cut->next = prev;
        }
        else {
            head = prev;
        }
        
        tempTail->next = temp;
        return head;
    }
};