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
    bool isUnivalTree(TreeNode* node, int val) {
        if (!node)
            return true;
        return node->val == val && isUnivalTree(node->left, val) && isUnivalTree(node->right, val);
    }
    
public:
    bool isUnivalTree(TreeNode* root) {
        if (!root)
            return true;
        return isUnivalTree(root, root->val);
    }
};