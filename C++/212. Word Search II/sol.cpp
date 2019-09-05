class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;
    string word;
    TrieNode() {
        isWord = false;
        word = "";
    }
};

class Trie {
private:
    TrieNode* root;
    
    void deleteNode(TrieNode* node) {
        for (auto child : node->children)
            deleteNode(child.second);
        free(node);
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children.count(c) <= 0)
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->isWord = true;
        cur->word = word;
    }
    
public:
    Trie(vector<string> &words) {
        root = new TrieNode();
        for (string w : words) {
            addWord(w);
        }
    } 
    
    ~Trie() {
        deleteNode(root);
    }
    
    TrieNode* getRoot() {
        return root;
    }
};

class Solution {
private:
    void findWords(int r, int c, TrieNode* node, vector<vector<char>>& board, unordered_set<string> &result) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == ' ') return;
        if (node->children.count(board[r][c]) > 0) {
            node = node->children[board[r][c]];
            if (node->isWord) result.insert(node->word);
            char temp = board[r][c];
            board[r][c] = ' ';
            findWords(r-1, c, node, board, result);
            findWords(r, c-1, node, board, result);
            findWords(r+1, c, node, board, result);
            findWords(r, c+1, node, board, result);
            board[r][c] = temp;
        }
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty()) {
            vector<string> empty;
            return empty;
        }
        
        Trie* trie = new Trie(words);
        TrieNode* root = trie->getRoot();
        
        unordered_set<string> result_words;
        for (int i = 0; i < board.size(); ++i) 
            for (int j = 0; j < board[0].size(); ++j) 
                findWords(i, j, root, board, result_words);
        
        vector<string> ans;
        for (string w : result_words)
            ans.push_back(w);
        
        return ans;
    }
};