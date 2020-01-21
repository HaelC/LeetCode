class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> tokens;
        string buf;
        stringstream ss(s);
        int maxLen = 0;
        
        while (ss >> buf) {
            tokens.push_back(buf);
            maxLen = max(maxLen, (int)buf.length());
        }
        
        vector<string> result(maxLen, "");
        for (int i = 0; i < maxLen; i++) {
            for (int j = 0; j < tokens.size(); j++) {
                result[i] += i < tokens[j].length() ? tokens[j][i] : ' ';
            }
        }
        
        for (int i = 0; i < maxLen; i++) {
            string totrim = result[i];
            int j = totrim.length() - 1;
            for (; j >= 0; j--) {
                if (totrim[j] != ' ') {
                    break;
                }
            }
            result[i] = totrim.substr(0, j + 1);
        }
        
        return result;
    }
};