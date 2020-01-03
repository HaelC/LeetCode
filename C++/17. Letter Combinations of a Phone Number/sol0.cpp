class Solution {
private:
    void backtracking(vector<string>& letters, string digits, string current, int i) {
        if (i == digits.size()) {
            letters.push_back(current);
            return;
        }
        char digit = digits[i];
        switch(digit) {
            case '2':
                backtracking(letters, digits, current + 'a', i + 1);
                backtracking(letters, digits, current + 'b', i + 1);
                backtracking(letters, digits, current + 'c', i + 1);
                break;
            case '3':
                backtracking(letters, digits, current + 'd', i + 1);
                backtracking(letters, digits, current + 'e', i + 1);
                backtracking(letters, digits, current + 'f', i + 1);
                break;
            case '4':
                backtracking(letters, digits, current + 'g', i + 1);
                backtracking(letters, digits, current + 'h', i + 1);
                backtracking(letters, digits, current + 'i', i + 1);
                break;
            case '5':
                backtracking(letters, digits, current + 'j', i + 1);
                backtracking(letters, digits, current + 'k', i + 1);
                backtracking(letters, digits, current + 'l', i + 1);
                break;
            case '6':
                backtracking(letters, digits, current + 'm', i + 1);
                backtracking(letters, digits, current + 'n', i + 1);
                backtracking(letters, digits, current + 'o', i + 1);
                break;
            case '7':
                backtracking(letters, digits, current + 'p', i + 1);
                backtracking(letters, digits, current + 'q', i + 1);
                backtracking(letters, digits, current + 'r', i + 1);
                backtracking(letters, digits, current + 's', i + 1);
                break;
            case '8':
                backtracking(letters, digits, current + 't', i + 1);
                backtracking(letters, digits, current + 'u', i + 1);
                backtracking(letters, digits, current + 'v', i + 1);
                break;
            case '9':
                backtracking(letters, digits, current + 'w', i + 1);
                backtracking(letters, digits, current + 'x', i + 1);
                backtracking(letters, digits, current + 'y', i + 1);
                backtracking(letters, digits, current + 'z', i + 1);
                break;
            default:
                break;
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> letters;
        if (digits.empty()) {
            return letters;
        }
        
        backtracking(letters, digits, "", 0);
        return letters;
    }
};