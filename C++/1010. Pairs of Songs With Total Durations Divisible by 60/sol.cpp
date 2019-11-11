class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;
        vector<int> table(60, 0);
        for (int t : time) {
            result += table[(60 - t % 60) % 60];
            table[t % 60]++;
        }
        return result;
    }
};