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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preBegin, int preEnd, int inBegin, int inEnd) {
        if (preBegin >= preEnd || inBegin >= inEnd)
            return NULL;
        int rootVal = preorder[preBegin];
        TreeNode* root = new TreeNode(rootVal);
        auto f = find(inorder.begin() + inBegin, inorder.begin() + inEnd, rootVal);
        int distance = f - inorder.begin() - inBegin;
        root->left = buildTree(preorder, inorder, preBegin + 1, preBegin + distance + 1, inBegin, inBegin + distance);
        root->right = buildTree(preorder, inorder, preBegin + distance + 1, preEnd, inBegin + distance + 1, inEnd);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
        return root;
    }
};