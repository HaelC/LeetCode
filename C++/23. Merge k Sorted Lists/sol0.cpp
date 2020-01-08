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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> allNodes;
        for (auto list : lists) {
            while (list) {
                allNodes.push_back(list->val);
                list = list->next;
            }
        }
        sort(allNodes.begin(), allNodes.end());
        
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        for (auto node : allNodes) {
            p->next = new ListNode(node);
            p = p->next;
        }
        return head->next;
    }
};