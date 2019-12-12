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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> bfs;
        vector<vector<int>> result;
        if (!root) return result;
        bfs.push(root);
        bool leftToRight = true;
        while (!bfs.empty()) {
            int size = bfs.size();
            vector<int> row;
            if (leftToRight) {
                
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
            }
            else {
                stack<int> s;
                for (int i = 0; i < size; i++) {
                    TreeNode* node = bfs.front();
                    bfs.pop();
                    s.push(node->val);
                    if (node->left) {
                        bfs.push(node->left);
                    }
                    if (node->right) {
                        bfs.push(node->right);
                    }
                }
                while (!s.empty()) {
                    row.push_back(s.top());
                    s.pop();
                }
            }
            result.push_back(row);
            leftToRight = !leftToRight;
        }
        return result;
    }
};