class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int, int>> temp;
        int size = T.size();
        vector<int> result(size, 0);
        
        for (int i = size - 1; i >= 0; --i) {
            int temperature = T[i];
            while (!temp.empty() && temp.top().first <= temperature)
                temp.pop();
            result[i] = temp.empty() ? 0 : temp.top().second - i;
            temp.push({temperature, i});
        }
        return result;
    }
};