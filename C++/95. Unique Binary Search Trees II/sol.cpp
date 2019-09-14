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
    vector<TreeNode*> generateTrees(int begin, int end) {
        vector<TreeNode*> result;
        if (begin > end) {
            result.push_back(NULL);
            return result;
        }
        if (begin == end) {
            result.push_back(new TreeNode(begin));
            return result;
        }
        vector<TreeNode*> left, right;
        for (int i = begin; i <= end; ++i) {
            left = generateTrees(begin, i-1);
            right = generateTrees(i+1, end);
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        if (!n) {
            vector<TreeNode*> result;
            return result;
        }
        return generateTrees(1, n);
    }
};

// https://leetcode.com/explore/learn/card/recursion-i/253/conclusion/2384/discuss/31494/A-simple-recursive-solution