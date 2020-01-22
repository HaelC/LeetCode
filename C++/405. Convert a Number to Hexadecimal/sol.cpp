class Solution {
public:
    string toHex(int num) {
        string result = "";
        vector<char> hexadecimal{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        for (int i = 0; i < 8; i++) {
            result = hexadecimal[num & 15] + result;
            num >>= 4;
        }
        
        for (int i = 0; i < 8; i++) {
            if (result[i] != '0') {
                return result.substr(i);
            }
        }
        return "0";
    }
};