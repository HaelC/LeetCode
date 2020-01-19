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
    void traverse(TreeNode* node) {
        if (!node) {
            return;
        }
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        traverse(node->left);
        traverse(node->right);
    }
    
public:
    TreeNode* invertTree(TreeNode* root) {
        traverse(root);
        return root;
    }
};