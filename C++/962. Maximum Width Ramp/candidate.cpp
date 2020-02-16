class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int result = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = i + 1; j < A.size(); j++) {
                if (A[i] <= A[j]) {
                    result = max(result, j - i);
                }
            }
        }
        return result;
    }
};