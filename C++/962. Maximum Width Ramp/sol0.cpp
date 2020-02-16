class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        vector<pair<int, int>> valIndexPair;
        for (int i = 0; i < A.size(); i++) {
            valIndexPair.push_back({A[i], i});
        }
        sort(valIndexPair.begin(), valIndexPair.end());
        
        int currentMin = valIndexPair[0].second, result = 0;
        for (int i = 1; i < valIndexPair.size(); i++) {
            int index = valIndexPair[i].second;
            currentMin = min(currentMin, index);
            result = max(result, index - currentMin);
        }
        return result;
    }
};