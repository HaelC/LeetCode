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
        if (!node) {
            return 0;
        }
        return max(depth(node->left), depth(node->right)) + 1;
    }
    
    int addDeepest(TreeNode* node, int deepest, int currentDepth) {
        if (!node) {
            return 0;
        }
        if (deepest == currentDepth) {
            return node->val;
        }
        return addDeepest(node->left, deepest, currentDepth + 1) + addDeepest(node->right, deepest, currentDepth + 1);
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        int deepest = depth(root);
        return addDeepest(root, deepest, 1);
    }
};