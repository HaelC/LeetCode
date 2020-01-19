class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> hashmap;
        stringstream ss1(A);
        string buf;
        while (ss1 >> buf) {
            hashmap[buf]++;
        }
        
        stringstream ss2(B);
        while (ss2 >> buf) {
            hashmap[buf]++;
        }
        
        vector<string> result;
        for (auto p : hashmap) {
            if (p.second == 1) {
                result.push_back(p.first);
            }
        }
        return result;
    }
};