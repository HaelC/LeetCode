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
    int sum = 0;
    
    void sumPath(TreeNode* node, int val) {
        int currentVal = val * 2 + node->val;
        if (!node->left && !node->right) {
            sum += currentVal;
            return;
        }
        if (node->left)
            sumPath(node->left, currentVal);
        if (node->right)
            sumPath(node->right, currentVal);
    } 
    
public:
    int sumRootToLeaf(TreeNode* root) {
        sumPath(root, 0);
        return sum;
    }
};