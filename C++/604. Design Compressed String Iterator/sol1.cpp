class StringIterator {
private:
    string s;
    int ptr = 0, num = 0;
    char c = ' ';
    
public:
    StringIterator(string compressedString): s(compressedString) {
        
    }
    
    char next() {
        if (!hasNext()) {
            return ' ';
        }
        if (num == 0) {
            c = s[ptr];
            ptr++;
            while (ptr < s.length() && isdigit(s[ptr])) {
                num = num * 10 + (s[ptr] - '0');
                ptr++;
            }
        }
        num--;
        return c;
    }
    
    bool hasNext() {
        return ptr < s.length() || num != 0;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */