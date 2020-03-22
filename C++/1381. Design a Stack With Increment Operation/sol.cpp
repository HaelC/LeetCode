class CustomStack {
private:
    vector<int> s;
    int size, n;
    
public:
    CustomStack(int maxSize) {
        size = maxSize;
        s = vector<int>(size, 0);
        n = 0;
    }
    
    void push(int x) {
        if (n >= size) {
            return;
        }
        s[n++] = x;
    }
    
    int pop() {
        if (n == 0) {
            return -1;
        }
        return s[--n];
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < k && i < n; i++) {
            s[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */