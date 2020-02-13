class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> hashmap;
        for (int answer : answers) {
            hashmap[answer]++;
        }
        
        int result = 0;
        for (auto p : hashmap) {
            result += max(p.first + 1, int(ceil(p.second * 1.0 / (p.first + 1))) * (p.first + 1));
        }
        return result;
    }
};