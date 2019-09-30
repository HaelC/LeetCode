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
    int left = 0;
    void traverseBinaryTree(TreeNode* node, bool flag) {
        if (!node->left && !node->right && flag) {
            left += node->val;
            return;
        }
        if (node->left) {
            traverseBinaryTree(node->left, true);
        }
        if (node->right) {
            traverseBinaryTree(node->right, false);
        }
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;
        traverseBinaryTree(root, false);
        return left;
    }
};