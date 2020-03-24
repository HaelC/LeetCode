class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int dresses = 0, n = machines.size();
        for (auto machine : machines) {
            dresses += machine;
        }   
        if (dresses % n) {
            return -1;
        }
        int dress = dresses / n, result = 0, curr = 0;
        
        for (int i = 0; i < n; i++) {
            machines[i] -= dress;
        }
        
        for (auto machine : machines) {
            curr += machine;
            result = max(result, max(machine, abs(curr)));
        }
        return result;
    }
};