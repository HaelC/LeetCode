class Solution {
private:
    void getRow(vector<int>& row, int r) {
        if (!r) return;
        getRow(row, r-1);
        
        vector<int> newRow;
        
        for (int i = 0; i <= r; ++i) {
            if (!i || i == r)
                newRow.push_back(1);
            else
                newRow.push_back(row[i-1] + row[i]);
        }
        row = newRow;
    }
    
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row{1};
        getRow(row, rowIndex);
        return row;
    }
};