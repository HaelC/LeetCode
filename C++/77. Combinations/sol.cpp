class Solution {
private:
    set<vector<int>> combs;
    
    void findComb(int n, int k, vector<int>& comb, int cur) {
        if (cur > n)
            return;
        if (comb.size() == k) {
            combs.insert(comb);
        }
        else {
            for (int i = cur + 1; i <= n; i++) {
                comb.push_back(i);
                findComb(n, k, comb, i);
                comb.erase(comb.end() - 1);                     // backtracking
            }
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> comb;
        findComb(n, k, comb, 0);
        for (auto c : combs) {
            result.push_back(c);
        }
        return result;
    }
};