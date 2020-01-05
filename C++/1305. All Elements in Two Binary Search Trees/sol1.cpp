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
    
    void mergeTwoSortedArrays(vector<int>& v, vector<int>& v1, vector<int>& v2, int index1, int index2) {
        while (index1 < v1.size() || index2 < v2.size()) {
            if (index1 == v1.size()) {
                v.push_back(v2[index2++]);
            }
            else if (index2 == v2.size()) {
                v.push_back(v1[index1++]);
            }
            else {
                if (v1[index1] <= v2[index2]) {
                    v.push_back(v1[index1++]);
                }
                else {
                    v.push_back(v2[index2++]);
                }
            }
        }
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2, v;
        inorder(root1, v1);
        inorder(root2, v2);
        mergeTwoSortedArrays(v, v1, v2, 0, 0);
        return v;
    }
};