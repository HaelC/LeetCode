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
void insertNode(TreeNode* node, int val) {
    if (val < node->val) {
        if (!node->left) {
            TreeNode* child = new TreeNode(val);
            node->left = child;
            return;
        }
        else
            insertNode(node->left, val);
    }
    else {
        if (!node->right) {
            TreeNode* child = new TreeNode(val);
            node->right = child;
            return;
        }
        else 
            insertNode(node->right, val);
    }
}
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            root = new TreeNode(val);
        }
        else {
            insertNode(root, val);
        }
        return root;
    }
};