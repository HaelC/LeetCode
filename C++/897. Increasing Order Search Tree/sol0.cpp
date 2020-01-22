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
    void inorder(TreeNode* node, vector<int>& values) {
        if (!node) {
            return;
        }
        inorder(node->left, values);
        values.push_back(node->val);
        inorder(node->right, values);
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> values;
        inorder(root, values);
        TreeNode* head = new TreeNode(0);
        TreeNode* temp = head;
        for (int value : values) {
            temp->right = new TreeNode(value);
            temp = temp->right;
        }
        return head->right;
    }
};