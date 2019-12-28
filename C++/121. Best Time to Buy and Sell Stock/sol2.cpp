class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        vector<int> differences;
        for (int i = 1; i < prices.size(); i++) {
            differences.push_back(prices[i] - prices[i - 1]);
        }
        int profit = 0, current = 0;
        for (int diff : differences) {
            current = max(current + diff, diff);
            profit = max(profit, current);
        }
        return profit;
    }
};