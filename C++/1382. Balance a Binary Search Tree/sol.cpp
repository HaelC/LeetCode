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
    void inorder(TreeNode* node, vector<int>& sorted) {
        if (!node) {
            return;
        }
        inorder(node->left, sorted);
        sorted.push_back(node->val);
        inorder(node->right, sorted);
    }
    
    TreeNode* buildTree(vector<int>& array, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(array[mid]);
        node->left = buildTree(array, left, mid - 1);
        node->right = buildTree(array, mid + 1, right);
        return node;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sorted;
        inorder(root, sorted);
        return buildTree(sorted, 0, sorted.size() - 1);
    }
};