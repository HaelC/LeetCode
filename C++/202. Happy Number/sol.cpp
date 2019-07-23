class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hashmap;
        while (n != 1) {
            if (hashmap.count(n))
                return false;
            hashmap.insert(n);
            int temp = n;
            int sumSquare = 0;
            while (temp) {
                sumSquare += (temp % 10) * (temp % 10);
                temp /= 10;
            }
            n = sumSquare;
        }
        return true;
    }
};