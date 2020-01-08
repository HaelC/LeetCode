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
    string preorder(TreeNode* node) {
        if (!node) {
            return "null";
        }
        return "#" + to_string(node->val) + " " + preorder(node->left) + " " + preorder(node->right);
    }
    
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string str_s = preorder(s), str_t = preorder(t);
        return str_s.find(str_t) != string::npos;
    }
};