class Solution {
private:
    void generate(long curr, int low, int high, vector<int>& result) {
        if (curr > high) {
            return;
        }
        if (curr >= low) {
            result.push_back(curr);
        }
        if (curr == 0) {
            return;
        }
        
        int lastDigit = curr % 10;
        long prev = curr * 10 + lastDigit - 1;
        long next = curr * 10 + lastDigit + 1;
        if (lastDigit != 0) {
            generate(prev, low, high, result);
        }
        if (lastDigit != 9) {
            generate(next, low, high, result);
        }
    }
    
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> result;
        for (int i = 0; i <= 9; i++) {
            generate(i, low, high, result);
        }
        sort(result.begin(), result.end());
        return result;
    }
};