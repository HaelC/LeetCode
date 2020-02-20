class Solution {
private:
    int gcd(int x, int y) {
        return x == 0 ? y : gcd(y % x, x);
    }
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> hashmap;
        for (int card : deck) {
            hashmap[card]++;
        }
        
        int divisor = 0;
        for (auto p : hashmap) {
            if (!divisor) {
                divisor = p.second;
            }
            else {
                divisor = gcd(divisor, p.second);
            }
        }
        
        return divisor >= 2;
    }
};