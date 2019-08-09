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
    bool findpath(TreeNode* root, TreeNode* node, unordered_set<int> &path, TreeNode*& ancestor) {
        if (!root)
            return false;
        if (root == node) {
            if (!ancestor && path.count(node->val) > 0)
                ancestor = node;
            path.insert(node->val);
            return true;
        }
        if (findpath(root->left, node, path, ancestor) || findpath(root->right, node, path, ancestor)) {
            if (!ancestor && path.count(root->val) > 0)
                ancestor = root;
            path.insert(root->val);
            return true;
        }
        else
            return false;
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