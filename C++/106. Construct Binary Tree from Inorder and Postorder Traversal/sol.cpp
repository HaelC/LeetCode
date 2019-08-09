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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inBegin, int inEnd, int postBegin, int postEnd) {
        if (inBegin >= inEnd || postBegin >= postEnd)
            return NULL;
        
        int rootVal = postorder[postEnd - 1];
        TreeNode* root = new TreeNode(rootVal);
        auto f = find(inorder.begin() + inBegin, inorder.begin() + inEnd, rootVal);
        int distance = f - inorder.begin() - inBegin;
        root->left = buildTree(inorder, postorder, inBegin, inBegin + distance,postBegin, postBegin + distance);
        root->right = buildTree(inorder, postorder, inBegin + distance + 1, inEnd, postBegin + distance, postEnd - 1);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = buildTree(inorder, postorder, 0, inorder.size(), 0, postorder.size());
        return root;
    }
};