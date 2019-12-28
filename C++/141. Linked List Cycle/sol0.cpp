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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> hashset;
        ListNode* temp = head;
        while (temp) {
            if (hashset.count(temp) > 0) {
                return true;
            }
            hashset.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};