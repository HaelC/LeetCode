class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = m ? image[0].size() : 0;
        
        int originalColor = image[sr][sc];
        image[sr][sc] = newColor;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<vector<bool>> visited(m, vector<bool>(n));
        visited[sr][sc] = true;
        
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first, c = p.second;
            if ((r - 1) >= 0 && image[r-1][c] == originalColor && !visited[r-1][c]) {
                image[r-1][c] = newColor;
                q.push({r-1, c});
                visited[r-1][c] = true;
            }
            if ((r + 1) < m && image[r+1][c] == originalColor && !visited[r+1][c]) {
                image[r+1][c] = newColor;
                q.push({r+1, c});
                visited[r+1][c] = true;
            }
            if ((c - 1) >= 0 && image[r][c-1] == originalColor && !visited[r][c-1]) {
                image[r][c-1] = newColor;
                q.push({r, c-1});
                visited[r][c-1] = true;
            }
            if ((c + 1) < n && image[r][c+1] == originalColor && !visited[r][c+1]) {
                image[r][c+1] = newColor;
                q.push({r, c+1});
                visited[r][c+1] = true;
            }
        }
        
        return image;
    }
};