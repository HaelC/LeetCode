class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long sum = 0, functionSum = 0, n = A.size();
        for (int i = 0; i < n; i++) {
            sum += A[i];
            functionSum += i * A[i];
        }
        long result = functionSum;
        for (int i = 1; i < n; i++) {
            functionSum += sum;
            functionSum -= A[n - i] * n;
            result = max(functionSum, result);
        }
        return result;
    }
};