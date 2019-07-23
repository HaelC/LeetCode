class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hashmap;
        unordered_map<string, int> common;
        for (int i = 0; i < list1.size(); ++i) {
            hashmap[list1[i]] = i;
        }
        for (int i = 0; i < list2.size(); ++i) {
            if (hashmap.count(list2[i])) {
                common[list2[i]] = hashmap[list2[i]] + i;
            }
        }
        vector<string> result;
        
        int minIndex = 2000;
        for (auto it = common.begin(); it != common.end(); ++it) {
            if (it->second < minIndex)
                minIndex = it->second;
        }
        for (auto it = common.begin(); it != common.end(); ++it) {
            if (it->second == minIndex)
                result.push_back(it->first);
        }
        return result;
    }
};