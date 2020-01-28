class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int shortest = INT_MAX, index1 = -1, index2 = -1;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                if (index2 != -1) {
                    shortest = min(shortest, i - index2);
                }
                index1 = i;
            }
            else if (words[i] == word2) {
                if (index1 != -1) {
                    shortest = min(shortest, i - index1);
                }
                index2 = i;
            }
        }
        return shortest;
    }
};