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
    void removeLeaf(TreeNode*& node, int target) {
        if (!node) {
            return;
        }
        removeLeaf(node->left, target);
        removeLeaf(node->right, target);
        if (!node->left && !node->right) {
            if (node->val == target) {
                node = NULL;
            }
        }
    }
    
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        removeLeaf(root, target);
        return root;
    }
};