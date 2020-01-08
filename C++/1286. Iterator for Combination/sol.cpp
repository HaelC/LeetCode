class CombinationIterator {
private:
    vector<string> combinations;
    int index = 0;
    
    // void backtracking(string& s, unordered_set<char> visited, int len, string current) {
    //     if (current.length() == len) {
    //         combinations.push_back(current);
    //         return;
    //     }
    //     for (int i = 0; i < s.length(); i++) {
    //         if (visited.count(s[i]) == 0) {
    //             visited.insert(s[i]);
    //             backtracking(s, visited, len, current + s[i]);
    //             visited.erase(s[i]);
    //         }
    //     }
    // }
    void getCombination(string& s, int i, int len, string current) {
        if (current.length() == len) {
            combinations.push_back(current);
            return;
        }
        for (int j = i; j < s.length(); j++) {
            getCombination(s, j + 1, len, current + s[j]);
        }
    }
    
public:
    CombinationIterator(string characters, int combinationLength) {
        // unordered_set<char> visited;
        // backtracking(characters, visited, combinationLength, "");
        getCombination(characters, 0, combinationLength, "");
    }
    
    string next() {
        return combinations[index++];
    }
    
    bool hasNext() {
        return index < combinations.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */