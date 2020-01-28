class WordDistance {
private:
    unordered_map<string, vector<int>> hashmap;
    
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            hashmap[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int shortest = INT_MAX;
        for (int i1 : hashmap[word1]) {
            for (int i2: hashmap[word2]) {
                shortest = min(shortest, abs(i1 - i2));
            }
        }
        return shortest;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */