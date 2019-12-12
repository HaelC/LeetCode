class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banned_set;
        unordered_map<string, int> count;
        
        for (string s : banned) {
            banned_set.insert(s);
        }
        
        string word = "";
        int most_common_times = 0;
        string result = "";
        
        paragraph += '.';       // add a period to the end of paragraph to simplify the code
        for (int i = 0; i < paragraph.length(); i++) {
            if (isalpha(paragraph[i])) {
                word += tolower(paragraph[i]);
            }
            else {
                if (!word.empty() && banned_set.count(word) == 0) {
                    count[word]++;
                    if (count[word] > most_common_times) {
                        most_common_times = count[word];
                        result = word;
                    }
                }
                word = "";
            }
        }
        return result;
    }
};