class Solution {
private:
    map<string, int> parseFormula(string formula, int& index) {
        int len = formula.length();
        map<string, int> count;
        while (index < len && formula[index] != ')') {
            if (formula[index] == '(') {
                for (auto p : parseFormula(formula, ++index)) {
                    count[p.first] += p.second;
                }
            }
            else {
                int start = index;
                index++;
                while (index < len && islower(formula[index])) {
                    index++;
                }
                string element = formula.substr(start, index - start);
                start = index;
                while (index < len && isdigit(formula[index])) {
                    index++;
                }
                
                int num = (start == index) ? 1 : stoi(formula.substr(start, index - start));
                count[element] += num;
            }
        }
        // formula[index] == ')'
        int start = ++index;
        while (index < len && isdigit(formula[index])) {
            index++;
        }
        if (index != start) {
            int num = stoi(formula.substr(start, index - start));
            for (auto p : count) {
                count[p.first] *= num;
            } 
        }
        return count;
    }
    
public:
    string countOfAtoms(string formula) {
        int index = 0;
        string result = "";
        map<string, int> counts = parseFormula(formula, index);
        for (auto p : counts) {
            result += p.first;
            if (p.second > 1) {
                result += to_string(p.second);
            }
        }
        return result;
    }
};