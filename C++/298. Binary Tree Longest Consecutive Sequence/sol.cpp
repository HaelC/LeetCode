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
    void traverse(TreeNode* node, int& longest, int current, int value) {
        if (!node) {
            return;
        }
        if (node->val == value + 1) {
            current++;
        }
        else {
            current = 1;
        }
        longest = max(longest, current);
        traverse(node->left, longest, current, node->val);
        traverse(node->right, longest, current, node->val);
    }
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int longest = 1;
        traverse(root, longest, 0, 0);
        return longest;
    }
};