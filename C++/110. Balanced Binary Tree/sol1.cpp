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
    int depth(TreeNode* node) {
        if (!node)
            return 0;
        int left = depth(node->left);
        if (left == -1)
            return -1;
        int right = depth(node->right);
        if (right == -1)
            return -1;
        if (abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }
        
public:
    bool isBalanced(TreeNode* root) {
        return (depth(root) != -1);
    }
};