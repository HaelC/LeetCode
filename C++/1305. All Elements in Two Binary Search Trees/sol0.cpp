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
    void inorder(TreeNode* node, vector<int>& v) {
        if (!node) {
            return;
        }
        inorder(node->left, v);
        v.push_back(node->val);
        inorder(node->right, v);
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        inorder(root1, v1);
        inorder(root2, v2);
        v1.insert(v1.end(), v2.begin(), v2.end());
        sort(v1.begin(), v1.end());
        return v1;
    }
};