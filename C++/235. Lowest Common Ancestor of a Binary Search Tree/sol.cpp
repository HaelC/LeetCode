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
    void findpath(TreeNode* root, TreeNode* node, unordered_set<int> &path, TreeNode*& ancestor) {
        if (!root)
            return;
        if (path.count(root->val) > 0) {
            ancestor = root;
        }
        path.insert(root->val);
        if (root->val == node->val) {
            return;
        }
        else if (root->val > node->val) {
            findpath(root->left, node, path, ancestor);
        }
        else {
            findpath(root->right, node, path, ancestor);
        }
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_set<int> path;
        TreeNode* ancestor = NULL;
        findpath(root, p, path, ancestor);
        findpath(root, q, path, ancestor);
        return ancestor;
    }
};