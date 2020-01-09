class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseMap{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> unique;
        
        for (string word: words) {
            string encode = "";
            for (char c : word) {
                encode += morseMap[c - 'a'];
            }
            unique.insert(encode);
        }
        return unique.size();
    }
};