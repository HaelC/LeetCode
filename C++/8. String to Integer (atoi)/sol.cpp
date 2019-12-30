class Solution {
public:
    int myAtoi(string str) {
        int signal = 1, result = 0, i = 0, len = str.length(), threshold = INT_MAX / 10;
        while (i < len && isblank(str[i])) {
            i++;
        }
        if (i == len) {
            return result;
        }
        if (str[i] != '+' && str[i] != '-' && !isdigit(str[i])) {
            return result;
        }
        
        if (str[i] == '+') {
            i++;
        }
        else if (str[i] == '-') {
            signal = -1;
            i++;
        }
        
        while (i < len && isdigit(str[i])) {
            if (signal == 1) {
                if (result > threshold || (result == threshold && str[i] > '7')) {
                    return INT_MAX;
                }
            }
            else {
                if (result > threshold || (result == threshold && str[i] > '7')) {
                    return INT_MIN;
                }
            }
            result = result * 10 + (str[i] - '0');
            ++i;
        }
        return result * signal;
    }
};