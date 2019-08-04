class Solution {
private:
    pair<int, int> getOperand(stack<int> &operands) {
        int op1 = operands.top();
        operands.pop();
        int op2 = operands.top();
        operands.pop();
        return {op1, op2};
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        for (auto &s : tokens) {
            if (s == "+") {
                pair<int, int> ops = getOperand(operands);
                operands.push(ops.first + ops.second);
            }
            else if (s == "-") {
                pair<int, int> ops = getOperand(operands);
                operands.push(ops.second - ops.first);
            }
            else if (s == "*") {
                pair<int, int> ops = getOperand(operands);
                operands.push(ops.first * ops.second);
            }
            else if (s == "/") {
                pair<int, int> ops = getOperand(operands);
                operands.push(ops.second / ops.first);
            }
            else {
                int value = stoi(s);
                operands.push(value);
            }
        }
        return operands.top();
    }
};