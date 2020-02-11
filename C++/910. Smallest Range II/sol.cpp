class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int n = A.size();
        sort(A.begin(), A.end());
        
        int range = A[n - 1] - A[0];
        for (int i = 0; i < n - 1; i++) {
            int maximum = max(A[n - 1] - K, A[i] + K);
            int minimum = min(A[0] + K, A[i + 1] - K);
            range = min(range, maximum - minimum);
        }
        return range;
    }
};