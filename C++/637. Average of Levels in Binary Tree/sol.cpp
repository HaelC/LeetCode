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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (!root)
            return result;
        
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            int size = bfs.size();
            double sum = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = bfs.front();
                bfs.pop();
                sum += node->val;
                if (node->left)
                    bfs.push(node->left);
                if (node->right)
                    bfs.push(node->right);
            }
            result.push_back(sum / size);
        }
        return result;
    }
};