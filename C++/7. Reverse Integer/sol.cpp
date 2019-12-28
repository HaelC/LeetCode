class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN || x == 0) return 0;
        string s = to_string(x);
        
        int left = 0, right = s.length() - 1;
        if (s[0] == '-') {
            left = 1;
        }
        
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
        try {
            return stoi(s);
        }
        catch(...) {
            return 0;
        }
    }
};