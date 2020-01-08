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
    bool equals(TreeNode* s, TreeNode* t) {
        if (!s && !t) {
            return true;
        }
        if (!s || !t) {
            return false;
        }
        return (s->val == t->val && equals(s->left, t->left) && equals(s->right, t->right));
    }
    
    bool isSubtreeHelper(TreeNode* s, TreeNode* t) {
        return equals(s, t) || (s && (isSubtreeHelper(s->left, t) || isSubtreeHelper(s->right, t)));
    }
    
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return isSubtreeHelper(s, t);
    }
};