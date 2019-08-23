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
    int height(TreeNode* node) {
        if (!node)
            return 0;
        return max(height(node->left), height(node->right)) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
    }
};