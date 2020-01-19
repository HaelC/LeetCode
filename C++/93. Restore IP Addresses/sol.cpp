class Solution {
private:
    bool isValidPart(string s) {
        if (s.length() > 3) {
            return false;
        }
        if (s[0] == '0') {
            return s.length() == 1;
        }
        return (stoi(s) <= 255);
    }
    
    void backtracking(vector<string>& results, vector<string> parts, string s, int index) {
        if (parts.size() == 3) {
            if (isValidPart(s.substr(index))) {
                string ip = "";
                for (string part : parts) {
                    ip += part + '.';
                }
                ip += s.substr(index);
                results.push_back(ip);
            }
            return;
        }
        for (int i = 1; i <= 3 && index + i < s.length(); i++) {
            string part = s.substr(index, i);
            if (isValidPart(part)) {
                vector<string> temp = parts;
                temp.push_back(part);
                backtracking(results, temp, s, index + i);
            }
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> results, parts;
        backtracking(results, parts, s, 0);
        return results;
    }
};