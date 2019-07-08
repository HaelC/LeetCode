class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if (matrix.empty()) return v;
        
        int upper = 0, left = 0;
        int lower = matrix.size() - 1;
        int right = matrix[0].size() - 1;

        int cnt = 0, size = (lower + 1) * (right + 1);
        int i = 0, j = 0, direction = 0;
        while (cnt < size) {
            if (direction == 0) {
                while (j <= right) {
                    ++cnt;
                    v.push_back(matrix[i][j++]);
                    //cout << matrix[i][j++] << endl;
                    //++j;
                }
                if (cnt == size) break;
                //--right;
                ++upper;
                --j;
                ++i;
                direction = 1;
            }
            if (direction == 1) {
                while (i <= lower) {
                    ++cnt;
                    v.push_back(matrix[i++][j]);
                    //cout << matrix[i++][j] << endl;
                    //++i;
                }
                if (cnt == size) break;
                //--lower;
                --right;
                --i;
                --j;
                direction = 2;
            }
            if (direction == 2) {
                while (j >= left) {
                    ++cnt;
                    v.push_back(matrix[i][j--]);
                    //cout << matrix[i][j] << endl;
                    //--j;
                }
                if (cnt == size) break;
                //++left;
                --lower;
                ++j;
                --i;
                direction = 3;
            }
            if (direction == 3) {
                while (i >= upper) {
                    ++cnt;
                    v.push_back(matrix[i--][j]);
                    //cout << matrix[i][j] << endl;
                    //--i;
                }
                if (cnt == size) break;
                //++upper;
                ++left;
                ++i;
                ++j;
                direction = 0;
            }
        }
        return v;
    }
};