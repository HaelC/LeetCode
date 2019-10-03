class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        int result = 0;
        int upperThreshold = INT_MAX / 10;
        int i = 0;
        int signal = 1;
        while (i < len && isblank(str[i]))
            ++i;
        
        if (i == len)
            return result;
        
        if (str[i] == '+') {
            ++i;
        }
        else if (str[i] == '-') {
            signal = -1;
            ++i;
        }
        else if (!isdigit(str[i]))
            return result;
        
        while (i < len && isdigit(str[i])) {
            if (result > upperThreshold || (result == upperThreshold && str[i] >= '7')) {
                if (signal == 1)
                    return INT_MAX;
                else {
                    if (result == upperThreshold && str[i] == '7' && (i + 1 == len || !isdigit(str[i+1])))
                        return INT_MIN + 1;
                    else
                        return INT_MIN;
                }
            }
            result = result * 10 + (str[i] - '0');
            ++i;
        }
        
        return result * signal;
    }
};