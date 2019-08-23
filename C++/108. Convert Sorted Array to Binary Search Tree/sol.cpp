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
public:
    using iter = vector<int>::const_iterator;
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return NULL;
        return buildBST(nums.begin(), nums.end());
    }
    
    TreeNode* buildBST(iter begin, iter end) {
        if (begin >= end) 
            return NULL;
        
        iter middle = begin + (end - begin) / 2;
        
        TreeNode* node = new TreeNode(*middle);
        node->left = buildBST(begin, middle);
        node->right = buildBST(middle+1, end);
        
        return node;
    }
};