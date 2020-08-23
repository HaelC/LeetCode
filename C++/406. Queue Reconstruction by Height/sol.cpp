bool orderByHeight(vector<int> v1, vector<int> v2) {
    return v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
}

class Solution {
    
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> queue;
        sort(people.begin(), people.end(), orderByHeight);
        for (auto& p: people) {
            queue.insert(queue.begin() + p[1], p);
        }
        return queue;
    }
};