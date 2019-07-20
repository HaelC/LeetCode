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
        if (!head)
            return false;
        ListNode *fastNode = head->next;
        ListNode *slowNode = head;
        while (fastNode) {
            if (fastNode == slowNode)
                return true;
            if (!fastNode->next)
                return false;
            fastNode = fastNode->next->next;
            slowNode = slowNode->next;
        }
        return false;
    }
};