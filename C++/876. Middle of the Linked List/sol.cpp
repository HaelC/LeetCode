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
    ListNode* middleNode(ListNode* head) {
        int num = 0;
        ListNode* temp = head;
        while (temp) {
            num++;
            temp = temp->next;
        }
        
        int target = num / 2;
        temp = head;
        for (int i = 0; i < target; i++) {
            temp = temp->next;
        }
        return temp;
    }
};