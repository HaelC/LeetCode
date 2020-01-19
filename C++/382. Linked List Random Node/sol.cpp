/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private: 
    int length = 0;
    ListNode* ll = NULL;
    
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        ll = head;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        delete(temp);
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int step = rand() % length;
        ListNode* temp = ll;
        for (int i = 0; i < step; i++) {
            temp = temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */