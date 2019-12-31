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
    void bstToSortedArray(TreeNode* node, vector<int>& inorder) {
        if (!node) {
            return;
        }
        bstToSortedArray(node->left, inorder);
        inorder.push_back(node->val);
        bstToSortedArray(node->right, inorder);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        bstToSortedArray(root, inorder);
        return inorder[k - 1];
    }
};