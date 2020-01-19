/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void inorder(TreeNode* node, unordered_map<int, int>& count, int& maxFreq) {
        if (!node) {
            return;
        }
        inorder(node->left, count, maxFreq);
        count[node->val]++;
        maxFreq = max(maxFreq, count[node->val]);
        inorder(node->right, count, maxFreq);
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        int maxFreq = 0;
        unordered_map<int, int> count;
        inorder(root, count, maxFreq);
        vector<int> result;
        for (auto p : count) {
            if (p.second == maxFreq) {
                result.push_back(p.first);
            }
        }
        return result;
    }
};