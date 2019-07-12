class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row{1};
        if (!rowIndex)
            return row;
        
        row.push_back(1);
        vector<int> lastRow;
        
        for (int i = 1; i < rowIndex; ++i) {
            lastRow = row;
            for (int j = 1; j < i + 1; ++j) {
                row[j] = lastRow[j-1] + lastRow[j];
            }
            row.push_back(1);
        }
        return row;
    }
};