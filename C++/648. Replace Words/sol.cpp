class Solution {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        string str;
    };
    TrieNode* root;
    
    void buildTrie(string s) {
        TrieNode* cur = root;
        for (char c : s) {
            if (cur->children.count(c) <= 0)
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->str = s;
    }
    
public:
    string replaceWords(vector<string>& dict, string sentence) {
        vector<string> tokens;
        string buf;
        stringstream ss(sentence);
        
        while (ss >> buf)
            tokens.push_back(buf);
        
        root = new TrieNode();
        for (string word : dict)
            buildTrie(word);
        
        for (string &word : tokens) {
            TrieNode* cur = root;
            for (char c : word) {
                if (cur->children.count(c) <= 0) {
                    break;
                }
                cur = cur->children[c];
                if (!cur->str.empty()) {
                    word = cur->str;
                    break;
                }
            }
        }
        
        stringstream ss1;
        for (int i = 0; i < tokens.size(); ++i) {
            if (i)
                ss1 << " ";
            ss1 << tokens[i];
        }
        
        return ss1.str();
    }
};