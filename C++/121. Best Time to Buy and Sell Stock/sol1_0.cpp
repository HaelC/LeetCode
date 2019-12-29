class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        
        int n = prices.size();
        int minPriceSoFar = prices[0];
        vector<int> profits(n, 0);
        for (int i = 1; i < n; i++) {
            if (prices[i] < minPriceSoFar) {
                minPriceSoFar = prices[i];
            }
            else {
                profits[i] = prices[i] - minPriceSoFar;
            }
        }
        
        return *max_element(profits.begin(), profits.end());
    }
};