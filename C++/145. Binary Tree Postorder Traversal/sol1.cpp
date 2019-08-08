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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> result;
        TreeNode* last = NULL;
        
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            }
            else {
                TreeNode* node = s.top();
                if (node->right && last != node->right) {
                    root = node->right;
                }
                else {
                    result.push_back(node->val);
                    last = node;
                    s.pop();
                }
            }
        }
        return result;
    }
};