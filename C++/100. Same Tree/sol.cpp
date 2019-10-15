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
    bool check(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        return p->val == q->val;
    }
    
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> nodeQueue;
        if (!check(p, q))
            return false;
        nodeQueue.push(p);
        nodeQueue.push(q);
        while (!nodeQueue.empty()) {
            p = nodeQueue.front();
            nodeQueue.pop();
            q = nodeQueue.front();
            nodeQueue.pop();
            if (!check(p, q))
                return false;
            if (p && q) {
                nodeQueue.push(p->left);
                nodeQueue.push(q->left);
            
                nodeQueue.push(p->right);
                nodeQueue.push(q->right);
            }
        }
        return true;
    }
};