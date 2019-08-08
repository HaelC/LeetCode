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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (!node)
                    level.push_back(INT_MIN);
                else {
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            for (int j = 0; j < level.size() / 2; ++j) {
                if (level[j] != level[level.size() - j - 1])
                    return false;
            }
        }
        
        return true;
    }
};