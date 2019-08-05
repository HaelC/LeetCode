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
    void inorder(vector<int> &result, TreeNode* node) {
        if (!node)
            return;
        inorder(result, node->left);
        result.push_back(node->val);
        inorder(result, node->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(result, root);
        return result;
    }
};