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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> hashset;
        ListNode* p = headA;
        while (p) {
            hashset.insert(p);
            p = p->next;
        }
        
        p = headB;
        while (p) {
            if (hashset.count(p) > 0) {
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }
};