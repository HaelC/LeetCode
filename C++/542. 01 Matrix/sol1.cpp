class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j]) {
                    queue<pair<int, int>> q;
                    set<pair<int, int>> s;
                    int step = 0;
                    q.push({i, j});
                    s.insert({i, j});
                    while (!q.empty()) {
                        int size = q.size();
                        ++step;
                        int flag = 0;
                        for (int k = 0; k < size; ++k) {
                            pair<int, int> p = q.front();
                            int r = p.first, c = p.second;
                            if (((r - 1) >= 0 && !matrix[r-1][c]) || ((r + 1) < m && !matrix[r+1][c])
                                || ((c - 1) >= 0 && !matrix[r][c-1]) || ((c + 1) < n && !matrix[r][c+1])) {
                                result[i][j] = step;
                                flag = 1;
                                break;
                            }
                            if ((r - 1) >= 0 && matrix[r-1][c] && s.find({r-1, c}) == s.end()) {
                                q.push({r-1, c});
                                s.insert({r-1, c});
                            }
                            if ((r + 1) < m && matrix[r+1][c] && s.find({r+1, c}) == s.end()) {
                                q.push({r+1, c});
                                s.insert({r+1, c});
                            }
                            if ((c - 1) >= 0 && matrix[r][c-1] && s.find({r, c-1}) == s.end()) {
                                q.push({r, c-1});
                                s.insert({r, c-1});
                            }
                            if ((c + 1) < n && matrix[r][c+1] && s.find({r, c+1}) == s.end()) {
                                q.push({r, c+1});
                                s.insert({r, c+1});
                            }
                            q.pop();
                        }
                        if (flag) break;
                    }
                }
            }
        }
        return result;
    }
};