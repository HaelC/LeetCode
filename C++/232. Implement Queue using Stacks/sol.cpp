class MyQueue {
private:
    stack<int> s;
    void pushHelper(int x) {
        if (s.empty()) {
            s.push(x);
            return;
        }
        int val = s.top();
        s.pop();
        pushHelper(x);
        s.push(val);
    }
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        pushHelper(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int result = s.top();
        s.pop();
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        return s.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */