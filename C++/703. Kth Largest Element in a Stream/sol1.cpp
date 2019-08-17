class KthLargest {
private:
    struct TreeNode {
        int val;
        int count;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), count(1), left(NULL), right(NULL) {}
    };
    
    TreeNode* root = NULL;
    int kth = 0;
    
    TreeNode* insert(TreeNode* node, int num) {
        if (!node)
            return new TreeNode(num);
        node->count++;
        if (num < node->val) {
            node->left = insert(node->left, num);
        }
        else {
            node->right = insert(node->right, num);
        }
        return node;
    }
    
    int findKthLargest() {
        int count = kth;
        TreeNode* walker = root;
        while (count > 0) {
            int pos = 1 + (walker->right ? walker->right->count : 0);
            if (count == pos)
                break;
            else if (count > pos) {
                count -= pos;
                walker = walker->left;
            }
            else {
                walker = walker->right;
            }
        }
        return walker->val;
    }
    
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for (auto num: nums) {
            root = insert(root, num);
        }
    }
    
    int add(int val) {
        root = insert(root, val);
        return findKthLargest();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */