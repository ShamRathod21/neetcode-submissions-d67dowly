class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> pStack;
        int num1,num2;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+") {
                num2 = pStack.top();
                pStack.pop();
                num1 = pStack.top();
                pStack.pop();
                pStack.push(num1+num2);
            } else if (tokens[i] == "-") {
                num2 = pStack.top();
                pStack.pop();
                num1 = pStack.top();
                pStack.pop();
                pStack.push(num1-num2);
            } else if (tokens[i] == "*") {
                num2 = pStack.top();
                pStack.pop();
                num1 = pStack.top();
                pStack.pop();
                pStack.push(num1*num2);
            } else if (tokens[i] == "/") {
                num2 = pStack.top();
                pStack.pop();
                num1 = pStack.top();
                pStack.pop();
                pStack.push(num1/num2);
            } else {
                pStack.push(stoi(tokens[i]));
            }
        }
        return pStack.top();
    }
};
