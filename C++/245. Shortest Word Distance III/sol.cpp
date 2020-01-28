class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int shortest = INT_MAX, i1 = -1, i2 = -1;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                i1 = i;
            }
            if (words[i] == word2) {
                if (word1 == word2) {
                    i1 = i2;
                }
                i2 = i;
            }
            if (i1 != -1 && i2 != -1) {
                shortest = min(shortest, abs(i2 - i1));
            }
        }
        return shortest;
    }
};