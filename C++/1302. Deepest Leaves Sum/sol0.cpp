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
    int deepestLeavesSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int sum = 0;
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            int size = bfs.size();
            sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();
                if (node->left) {
                    bfs.push(node->left);
                }
                if (node->right) {
                    bfs.push(node->right);
                }
                sum += node->val;
            }
        }
        return sum;
    }
};