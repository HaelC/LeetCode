class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> letterCountInB(26, 0);
        for (string s : B) {
            vector<int> temp(26, 0);
            for (char c : s) {
                temp[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                letterCountInB[i] = max(letterCountInB[i], temp[i]);
            }
        }
        
        vector<string> subsets;
        for (string s : A) {
            vector<int> letterCountInA(26, 0);
            bool universal = true;
            for (char c : s) {
                letterCountInA[c - 'a']++;
            }
            
            for (int i = 0; i < 26; i++) {
                if (letterCountInA[i] < letterCountInB[i]) {
                    universal = false;
                    break;
                }
            }
            
            if (universal) {
                subsets.push_back(s);
            }
        }
        return subsets;
    }
};