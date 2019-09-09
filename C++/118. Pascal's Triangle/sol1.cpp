class Solution {
private:
    void generate(vector<vector<int>> &result, int i) {
        if (!i) {
            vector<int> row{1};
            result.push_back(row);
            return;
        }
        generate(result, i-1);
        
        vector<int> row;
        //row.push_back(1);
        for (int j = 0; j <= i; ++j) {
            if (!j || i == j)
                row.push_back(1);
            else
                row.push_back(result[i-1][j-1] + result[i-1][j]);
        }
        result.push_back(row);
    }
    
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (!numRows) return result;
        generate(result, numRows-1);
        return result;
    }
};