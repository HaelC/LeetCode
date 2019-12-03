class Solution {
private:
    void dfs(vector<vector<int>>& M, int i, unordered_set<int>& visited) {
        for (int j = 0; j < M.size(); j++) {
            if (M[i][j] == 1 && visited.count(j) == 0) {
                visited.insert(j);
                dfs(M, j, visited);
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& M) {
        unordered_set<int> visited;
        int circles = 0;
        for (int i = 0; i < M.size(); i++) {
            if (visited.count(i) == 0) {
                dfs(M, i, visited);
                circles++;
            }
        }
        return circles;
    }
};