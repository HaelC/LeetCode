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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return NULL;
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            TreeNode* node;
            if (root->left && root->right) {
                node = root->right;
                while (node->left) {
                    node = node->left;
                }
                node->left = root->left;
                node = root->right;
            }
            else if (root->left) {
                node = root->left;
            }
            else if (root->right) {
                node = root->right;
            }
            delete root;
            return node;
        }
        return root;
    }
};