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
    vector<int> nodes;
    
    void inorder(TreeNode* node) {
        if (!node)
            return;
        inorder(node->left);
        nodes.push_back(node->val);
        inorder(node->right);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int l = 0, r = nodes.size() - 1;
        while (l < r) {
            int diff = k - nodes[r];
            if (nodes[l] == diff) {
                return true;
            }
            else if (nodes[l] < diff) {
                l++;
            }
            else {
                r--;
            }
        }
        return false;
    }
};