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
    vector<int> it;
    int size;
    int i = 0;
    
    void inorder(TreeNode* node, vector<int> &it) {
        if (!node)
            return;
        inorder(node->left, it);
        it.push_back(node->val);
        inorder(node->right, it);
    } 
public:
    BSTIterator(TreeNode* root) {
        inorder(root, it);
        size = it.size();
    }
    
    /** @return the next smallest number */
    int next() {
        return it[i++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return i < size;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */