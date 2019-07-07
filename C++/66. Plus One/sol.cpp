class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1]++;
        int allNine = 1;
        
        for (int i = digits.size() - 1; i >= 1; --i) {
            if (digits[i] > 9) {
                digits[i] -= 10;
                digits[i-1]++;
            }
            else {
                allNine = 0;
                break;
            }
        }

        if (digits[0] > 9)
            digits[0] -= 10;
        else
            allNine = 0;

        if (allNine) {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};