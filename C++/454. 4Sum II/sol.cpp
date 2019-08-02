class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> hashmap;
        for (auto &num1 : A) {
            for (auto &num2 : B) {
                ++hashmap[num1+num2];
            }
        }
        
        int result = 0;
        for (auto &num1 : C) {
            for (auto &num2 : D) {
                auto it = hashmap.find(0 - num1 - num2);
                if (it != hashmap.end())
                    result += it->second;
            }
        }
        
        return result;
    }
};