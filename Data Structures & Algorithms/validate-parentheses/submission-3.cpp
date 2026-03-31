class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        for(auto i : s) {
            if(i == '(' || i == '{' || i == '[') {
                charStack.push(i);
            } else {
                if(charStack.empty())
                    return false;
                char ch = charStack.top();
                if((i == ']' && ch != '[') || (i == ')' && ch != '(') || (i == '}' && ch != '{'))
                    return false;
                charStack.pop();
            }
        }  
        if(charStack.empty())
                return true;
        return false;          
    }
};
