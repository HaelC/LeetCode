class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> unique(n, 0);
        for (int i = 0; i < n / 2; i++) {
            unique[i] = i + 1;
            unique[n - 1 - i] = -i - 1;
        }
        return unique;
    }
};