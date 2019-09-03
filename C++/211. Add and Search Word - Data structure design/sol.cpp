class WordDictionary {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isWord;
    };
    
    TrieNode* root;
    
    bool searchWithDot(TrieNode* node, string word, string::iterator it) {
        if (it == word.end() || *it == '\0') {
            return node->isWord;
        }
        if (*it == '.') {
            for (auto child : node->children) {
                if (searchWithDot(child.second, word, it+1))
                    return true;
            }
        }
        else {
            if (node->children.count(*it) <= 0)
                return false;
            return searchWithDot(node->children[*it], word, it+1);
        }
        return false;
    }
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children.count(c) <= 0)
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        TrieNode* cur = root;
        for (auto it = word.begin(); it != word.end(); ++it) {
            if (*it == '.') {
                return searchWithDot(cur, word, it);
            }
            else {
                if (cur->children.count(*it) <= 0)
                    return false;
                else
                    cur = cur->children[*it];
            }
        }
        return cur->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */