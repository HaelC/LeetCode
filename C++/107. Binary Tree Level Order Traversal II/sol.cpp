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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        stack<vector<int>> s;
        queue<TreeNode*> bfs;
        
        if (!root) return result;
        bfs.push(root);
        while (!bfs.empty()) {
            int size = bfs.size();
            vector<int> row;
            for (int i = 0; i < size; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();
                row.push_back(node->val);
                if (node->left) {
                    bfs.push(node->left);
                }
                if (node->right) {
                    bfs.push(node->right);
                }
            }
            s.push(row);
        }
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
};