class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> hashmap;
        for (auto c : S) {
            if (hashmap.count(c) > 0)
                hashmap[c]++;
            else
                hashmap[c] = 1;
        }
        
        int result = 0;
        for (auto c : J) {
            if (hashmap.count(c) > 0)
                result += hashmap[c];
        }
        return result;
    }
};