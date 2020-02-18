class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int INF = 1e9;
        vector<vector<int>> dp(K + 2, vector<int>(n, INF));
        
        for (int i = 0; i <= K+1; i++) {
            dp[i][src] = 0;
        }
        
        for (int i = 1; i <= K+1; i++) {
            for (auto flight: flights) {
                int from = flight[0], to = flight[1], cost = flight[2];
                dp[i][to] = min(dp[i][to], dp[i - 1][from] + cost);
            }
        }
        
        return dp[K+1][dst] == INF ? -1 : dp[K+1][dst];
    }
};