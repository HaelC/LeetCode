class Solution {
private:
    unordered_map<int, int> stepMap;
    
public:
    int climbStairs(int n) {
        if (stepMap.count(n))
            return stepMap[n];
        
        int result;
        if (n < 3) 
            result = n;
        else
            result = climbStairs(n-1) + climbStairs(n-2);
        
        stepMap[n] = result;
        return result;
    }
};