// Your runtime beats 28.98 % of cpp submissions.
// Your memory usage beats 17.40 % of cpp submissions.

class MyHashMap {
private:
    int a[1000001];
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        for (int i = 0; i <= 1000000; ++i)
            a[i] = -1;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        a[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return a[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        a[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */