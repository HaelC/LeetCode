class Solution {
private:
    string getPrototype(string s) {
        string prototype = "";
        int shift = s[0] - 'a';
        for (char c : s) {
            char shifted = c - shift;
            if (shifted < 'a') {
                shifted += 26;
            }
            prototype += shifted;
        }
        return prototype;
    }
    
    
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> hashmap;
        for (auto s : strings) {
            hashmap[getPrototype(s)].push_back(s);
        }
        vector<vector<string>> result;
        for (auto p : hashmap) {
            result.push_back(p.second);
        }
        return result;
    }
};