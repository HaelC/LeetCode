class MapSum {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        int value;
    };
    
    TrieNode* root;
    unordered_map<string, int> hashmap;
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* cur = root;
        if (hashmap.count(key) > 0) {
            cur->value = cur->value - hashmap[key] + val;
            for (auto c : key) {
                cur = cur->children[c];
                cur->value = cur->value - hashmap[key] + val;
            }
        }
        else {
            cur->value += val;
            for (auto c : key) {
                if (cur->children.count(c) <= 0)
                    cur->children[c] = new TrieNode();
                cur = cur->children[c];
                cur->value += val;
            }
        }
        hashmap[key] = val;
    }
    
    int sum(string prefix) {
        TrieNode* cur = root;
        for (auto c : prefix) {
            if (cur->children.count(c) <=0)
                //return cur->value;
                return 0;
            cur = cur->children[c];
        }
        return cur->value;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */