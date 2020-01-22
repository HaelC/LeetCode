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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int length = 0;
        ListNode* temp = root;
        while (temp) {
            length++;
            temp = temp->next;
        }
        
        int partSize = length / k;
        vector<ListNode*> result(k, NULL);
        
        temp = root;
        for (int i = 0; i < length % k; i++) {
            result[i] = temp;
            for (int j = 0; j < partSize; j++) {
                temp = temp->next;
            }
            ListNode* next = temp->next;
            temp->next = NULL;
            temp = next;
        }
        
        if (partSize) {
            for (int i = length % k; i < k; i++) {
                result[i] = temp;
                for (int j = 0; j < partSize - 1; j++) {
                    temp = temp->next;
                }
                ListNode* next = temp->next;
                temp->next = NULL;
                temp = next;
            }
        }
        
        return result;
    }
};