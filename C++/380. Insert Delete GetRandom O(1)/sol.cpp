class RandomizedSet {
private:
    vector<int> randomSet;
    unordered_set<int> hashset;
    unordered_map<int, int> hashmap;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hashset.count(val) == 0) {
            hashset.insert(val);
            randomSet.push_back(val);
            hashmap[val] = randomSet.size() - 1;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hashset.count(val) > 0) {
            int index = hashmap[val];
            
            int temp = randomSet[index];
            randomSet[index] = randomSet[randomSet.size() - 1];
            hashmap[randomSet[index]] = index;
            randomSet[randomSet.size() - 1] = temp;
            randomSet.pop_back();
            
            hashmap.erase(val);
            hashset.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int randomIndex = rand() % randomSet.size();
        return randomSet[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */