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
    unordered_set<int> s;
    
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;
        if (s.count(root->val) > 0) 
            return true;
        s.insert(k - root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};