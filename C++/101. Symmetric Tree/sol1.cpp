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
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            int size = bfs.size();
            vector<string> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();
                if (node) {
                    level.push_back(to_string(node->val));
                    bfs.push(node->left);
                    bfs.push(node->right);
                }
                else {
                    level.push_back("");
                }
            }
            int n = level.size();
            for (int i = 0; i < n / 2; i++) {
                if (level[i] != level[n - i - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};