class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int currentMax = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = currentMax;
            currentMax = max(temp, currentMax);
        }
        arr[arr.size() - 1] = -1;
        return arr;
    }
};