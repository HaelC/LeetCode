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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        
        while (root || !s.empty()) {
            while (root) {
                result.push_back(root->val);
                s.push(root);
                root = root->left;
            }
            root = s.top()->right;
            s.pop();
        }
        return result;
    }
};