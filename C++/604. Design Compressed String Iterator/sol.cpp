class StringIterator {
private:
    int ptr = 0;
    vector<char> chars;
    vector<int> nums;
    
public:
    StringIterator(string compressedString) {
        for (int i = 0; i < compressedString.length(); ) {
            char c = compressedString[i];
            if (isalpha(c)) {
                chars.push_back(c);
                i++;
            }
            else {
                int num = 0;
                while (i < compressedString.length() && isdigit(compressedString[i])) {
                    num = num * 10 + (compressedString[i] - '0');
                    i++;
                }
                nums.push_back(num);
            }
        }
    }
    
    char next() {
        if (!hasNext()) {
            return ' ';
        }
        nums[ptr]--;
        char result = chars[ptr];
        if (nums[ptr] == 0) {
            ptr++;
        }
        return result;
    }
    
    bool hasNext() {
        return ptr != chars.size();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */