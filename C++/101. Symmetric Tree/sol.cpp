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
    bool isSymmetric(TreeNode* n1, TreeNode* n2) {
        if (!n1 && !n2)
            return true;
        else if (!n1 || !n2)
            return false;

        if (n1->val != n2->val)
            return false;

        return (isSymmetric(n1->left, n2->right) && isSymmetric(n1->right, n2->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
};