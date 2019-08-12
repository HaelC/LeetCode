/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> it;
    void findLeft(TreeNode* node) {
        while (node) {
            it.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        findLeft(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* node = it.top();
        it.pop();
        if (node->right)
            findLeft(node->right);
        return node->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !it.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */