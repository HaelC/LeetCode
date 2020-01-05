class Solution {
private:
    void jump(vector<int>& arr, int index, vector<bool>& visited) {
        visited[index] = true;
        if (arr[index] == 0) {
            return;
        }
        if (index + arr[index] < arr.size() && !visited[index + arr[index]]) {
            jump(arr, index + arr[index], visited);
        }
        if (index - arr[index] >= 0 && !visited[index - arr[index]]) {
            jump(arr, index - arr[index], visited);
        }
    }
    
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        jump(arr, start, visited);
        
        for (int i = 0; i < arr.size(); i++) {
            if (visited[i] && arr[i] == 0) {
                return true;
            }
        }
        
        return false;
    }
};