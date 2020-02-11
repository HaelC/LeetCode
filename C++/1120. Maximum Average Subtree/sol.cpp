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
    pair<int, int> traverse(TreeNode* node, double& result) {
        if (!node) {
            return {0, 0};
        }
        pair<int, int> left = traverse(node->left, result);
        pair<int, int> right = traverse(node->right, result);
        int sum = left.second + right.second + node->val;
        int num = left.first + right.first + 1;
        double ave = sum * 1.0 / num;
        if (ave > result) {
            result = ave;
        }
        return {num, sum};
    }
    
public:
    double maximumAverageSubtree(TreeNode* root) {
        double result = 0.0;
        traverse(root, result);
        return result;
    }
};