class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.length(), len_b = b.length();
        int carry = 0;

        if (len_a >= len_b) {
            for (int i = 0; i < len_b; ++i) {
                a[len_a-1-i] = addBinary(a[len_a-1-i], b[len_b-1-i], carry);
            }
            for (int i = len_a - len_b - 1; i >= 0; --i) {
                a[i] = addBinary(a[i], '0', carry);
            }
            if (carry)
                a = "1" + a;
            return a;
        }
        else {
            for (int i = 0; i < len_a; ++i) {
                b[len_b-1-i] = addBinary(b[len_b-1-i], a[len_a-1-i], carry);
            }
            for (int i = len_b - len_a - 1; i >= 0; --i) {
                b[i] = addBinary(b[i], '0', carry);
            }
            if (carry)
                b = "1" + b;
            return b;
        }
    }
    char addBinary(char a, char b, int &carry) {
        int a_digit = a - '0', b_digit = b - '0', result = 0;
        result = a_digit + b_digit + carry;
        if (result > 1) {
            carry = 1;
            result -= 2;
        }
        else
            carry = 0;
        return '0' + result;
    }
};