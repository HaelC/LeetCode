class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashmap;
        for (int i = 0; i < s.length(); ++i) {
            if (hashmap.count(s[i]) > 0) {
                hashmap[s[i]] = s.length();
            }
            else
                hashmap[s[i]] = i;
        }
        int minIndex = INT_MAX;
        for (auto it = hashmap.begin(); it != hashmap.end(); ++it) {
            if (it->second < s.length() && it->second < minIndex)
                minIndex = it->second;
        }
        if (minIndex == INT_MAX)
            return -1;
        else
            return minIndex;
    }
};