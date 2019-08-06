class Solution {
private:
    string decoder(string &s, int &i) {
        string result;
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                result += s[i++];
            else {
                int val = 0;
                while (isdigit(s[i]))
                    val = 10 * val + s[i++] - '0';
                
                ++i;
                string t = decoder(s, i);
                ++i;
                
                while (val-- > 0)
                    result += t;
            }
        }
        return result;
    }
    
public:
    string decodeString(string s) {      
        int i = 0;
        return decoder(s, i);
    }
};