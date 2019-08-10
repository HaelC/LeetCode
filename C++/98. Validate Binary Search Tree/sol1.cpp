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
    bool isValid(TreeNode* node, long min, long max) {
        if (!node)
            return true;
        if (node->val <= min || node->val >= max)
            return false;
        return (isValid(node->left, min, node->val) && isValid(node->right, node->val, max));
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};