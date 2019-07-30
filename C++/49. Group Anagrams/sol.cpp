class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        for (auto &str : strs) {
            string strCopy = str;
            sort(strCopy.begin(), strCopy.end());
            if (hashmap.count(strCopy) > 0) {
                hashmap[strCopy].push_back(str);
            }
            else {
                hashmap[strCopy] = vector<string>{str};
            }
        }
        vector<vector<string>> result;
        for (auto it = hashmap.begin(); it != hashmap.end(); ++it) {
            result.push_back(it->second);
        }
        return result;
    }
};