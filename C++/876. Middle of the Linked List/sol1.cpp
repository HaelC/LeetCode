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
        vector<ListNode*> aux(100);
        int num = 0;
        while (head) {
            aux[num++] = head;
            head = head->next;
        }
        return aux[num / 2];
    }
};