class Solution {
private:
    unordered_map<int, int> fibMap;
    
public:
    int fib(int N) {
        if (fibMap.count(N) > 0)
            return fibMap[N];
        
        int result;
        if (N < 2)
            result = N;
        else {
            result = fib(N-1) + fib(N-2);
        }
        
        fibMap[N] = result;
        return result;
    }
};