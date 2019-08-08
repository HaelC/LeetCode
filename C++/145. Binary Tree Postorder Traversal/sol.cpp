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
    void postorder(TreeNode* node, vector<int> &result) {
        if (!node)
            return;
        postorder(node->left, result);
        postorder(node->right, result);
        result.push_back(node->val);
    }
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        
        return result;
    }
};