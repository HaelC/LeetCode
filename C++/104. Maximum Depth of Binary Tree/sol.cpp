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
    int maxdepth = 0;
    
    void maxDepth(TreeNode* node, int depth) {
        if (!node)
            return;
        if (!node->left && !node->right) {
            maxdepth = max(maxdepth, depth);
        }
        maxDepth(node->left, depth+1);
        maxDepth(node->right, depth+1);
    }
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        maxDepth(root, 1);
        return maxdepth;
    }
};