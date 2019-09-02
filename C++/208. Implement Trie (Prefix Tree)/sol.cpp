class Trie {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isWord;
    };
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        int len = word.length();
        for (auto c : word) {
            if (cur->children.count(c) <= 0) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur->children.count(c) <= 0)
                return false;
            cur = cur->children[c];
        }
        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto c : prefix) {
            if (cur->children.count(c) <= 0)
                return false;
            cur = cur->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */