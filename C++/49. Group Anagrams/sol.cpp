class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> roots;
        for (string str : strs) {
            string original = str;
            sort(str.begin(), str.end());
            roots[str].push_back(original);
        }
        
        vector<vector<string>> anagrams;
        for (auto root : roots) {
            anagrams.push_back(root.second);
        }
        return anagrams;
    }
};