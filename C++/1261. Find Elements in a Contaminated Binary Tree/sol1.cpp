/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
private:
    TreeNode* rootNode;
    unordered_set<int> hashset;
    
    void recover(TreeNode* node) {
        if (!node) {
            return;
        }
        int x = node->val;
        hashset.insert(x);
        if (node->left) {
            node->left->val = 2 * x + 1;
        }
        if (node->right) {
            node->right->val = 2 * x + 2;
        }
        recover(node->left);
        recover(node->right);
    }
    
public:
    FindElements(TreeNode* root) {
        rootNode = root;
        if (rootNode->val) {
            rootNode->val = 0;
        }
        recover(rootNode);
        
    }
    
    bool find(int target) {
        return hashset.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */