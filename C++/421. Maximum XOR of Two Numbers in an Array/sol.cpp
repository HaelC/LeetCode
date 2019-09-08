class Solution {
private:
    struct TrieNode {
        TrieNode* left;
        TrieNode* right;
        int val;
        /*
        TrieNode(int x) {
            val = x;
        }
        */
    };
    
    TrieNode* root = new TrieNode();
    
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* cur = root;
        
        // Build the entire trie
        for (int n : nums) {
            for (int i = 31; i >= 0; --i) {
                int bit = n & (1 << i);
                if (bit) {
                    if (!cur->left)
                        cur->left = new TrieNode();
                    cur = cur->left;
                }
                else {
                    if (!cur->right)
                        cur->right = new TrieNode();
                    cur = cur->right;
                }
            }
            cur->val = n;
            cur = root;                                     // reset the node to root
        }
        
        int maxResult = 0;
        for (int n : nums) {
            for (int i = 31; i >= 0; --i) {
                int bit = n & (1 << i);
                if (bit) {
                    cur = cur->right ? cur->right : cur->left;
                }
                else {
                    cur = cur->left ? cur->left : cur->right;
                }
            }
            int result = n ^ cur->val;
            maxResult = max(maxResult, result);
            cur = root;
        }
        
        return maxResult;
    }
};

// reference:
// https://leetcode.com/explore/learn/card/trie/149/practical-application-ii/1057/discuss/130427/()-92