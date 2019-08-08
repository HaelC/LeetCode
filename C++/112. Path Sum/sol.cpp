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
    bool pathSum(TreeNode* node, int sum, int current) {
        if (!node && sum == current)
            return true;
        else if (node)
            if (node->left && node->right)
                return pathSum(node->left, sum, current + node->val) || pathSum(node->right, sum, current + node->val);
            else if (node->left)
                return pathSum(node->left, sum, current + node->val);
            else
                return pathSum(node->right, sum, current + node->val);
        return false;
    }
    
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        return pathSum(root, sum, 0);
    }
};