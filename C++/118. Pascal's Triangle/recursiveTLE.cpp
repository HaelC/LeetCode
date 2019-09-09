// Simple recursion, which takes much time

class Solution {
private:
    int pascalValue(int i, int j) {
        if (j == 0 || i == j)
            return 1;
        return pascalValue(i-1, j-1) + pascalValue(i-1, j);
    }
    
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; ++i) {
            vector<int> row;
            for (int j = 0; j <= i; ++j)
                row.push_back(pascalValue(i, j));
            result.push_back(row);
        }
        return result;
    }
};