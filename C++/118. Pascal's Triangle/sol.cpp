class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri;
        for (int i = 0; i < numRows; ++i)
        {
            if (i == 0) {
                vector<int> row{1};
                tri.push_back(row);
            }
            else if (i == 1) {
                vector<int> row{1, 1};
                tri.push_back(row);
            }
            else {
                vector<int> row{1};
                for (int j = 0; j < i-1; ++j)
                {
                    row.push_back(tri[i-1][j] + tri[i-1][j+1]);
                }
                row.push_back(1);
                tri.push_back(row);
            }
        }
        return tri;
    }
};