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
    void isValid(TreeNode* node, vector<int> &vals) {
        if (!node) {
            return;
        }
        else {
            isValid(node->left, vals);
            vals.push_back(node->val);
            isValid(node->right, vals);
        }
    }
    
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        vector<int> vals;
        isValid(root, vals);
        for (int i = 0; i < vals.size() - 1; ++i) 
            if (vals[i] >= vals[i+1])
                return false;
        
        
        return true;
    }
};