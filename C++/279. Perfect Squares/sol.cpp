class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        vector<bool> visited(n+1);
        
        for (int i = 1; i * i <= n; ++i) {
            squares.push_back(i * i);
        }
        
        if (squares.back() == n)
            return 1;
        
        queue<int> bfs;
        bfs.push(n);
        visited[n] = true;
        int step = 0;
        
        while (!bfs.empty()) {
            ++step;
            int size = bfs.size();
            for (int i = 0; i < size; ++i) {
                int num = bfs.front();
                for (auto square : squares) {
                    if (num - square == 0)
                        return step;
                    else if (num - square > 0 && !visited[num - square]) {
                        bfs.push(num - square);
                        visited[num - square] = true;
                    }
                }
                
                bfs.pop();
            }
        }
        return step;
    }
};