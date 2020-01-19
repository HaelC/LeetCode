class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> remainders(K, 0);
        remainders[0] = 1;
        int sum = 0, result = 0;
        for (int num : A) {
            sum += num;
            int remainder = sum % K;
            if (remainder < 0) {
                remainder += K;
            }
            remainders[remainder]++;
        }
        
        for (int remainder : remainders) {
            result += remainder * (remainder - 1) / 2;
        }
        return result;
    }
};