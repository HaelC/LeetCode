class Solution {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        int index;
        unordered_set<int> prePalindromes;
        TrieNode() {
            index = -1;
        }
    };
    
    TrieNode* root;
    
    // add the word to trie (in reversed order)
    void addWords(string word, int index) {
        TrieNode* cur = root;
        int len = word.length();
        for (int i = len - 1; i >= 0; --i) {
            if (cur->children.count(word[i]) <= 0)
                cur->children[word[i]] = new TrieNode();
            if (isPalindrome(word, 0, i))
                cur->prePalindromes.insert(index);
            cur = cur->children[word[i]];
        }
        cur->prePalindromes.insert(index);
        cur->index = index;
    }
    
    void searchPalindrome(string word, int index, vector<vector<int>>& result) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); ++i) {
            if (cur->index != -1 && cur->index != index && isPalindrome(word, i, word.length() - 1)) {
                vector<int> pair{index, cur->index};
                result.push_back(pair);
            }
            
            if (cur->children.count(word[i]) <= 0)
                return;
            cur = cur->children[word[i]];
        }
        
        for (int i : cur->prePalindromes) {
            if (index != i) {
                vector<int> pair{index, i};
                result.push_back(pair);
            }
        }
    }
    
    /*
    bool isPalindrome(string s) {
        int i = 0, len = s.length();
        while (i < len / 2) {
            if (s[i] != s[len-i-1])
                return false;
            ++i;
        }
        return true;
    }
    */
    
    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        root = new TrieNode();
        vector<vector<int>> result;
        for (int i = 0; i < words.size(); ++i) {
            addWords(words[i], i);
        }
        
        for (int i = 0; i < words.size(); ++i) {
            searchPalindrome(words[i], i, result);
        }
        
        return result;
    }
};

// Reference
// https://leetcode.com/explore/learn/card/trie/149/practical-application-ii/1138/discuss/79195/O(n-*-k2)-java-solution-with-Trie-structure