class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(auto i : str) {
            if(i == '[' || i == '(' || i == '{') {
                s.push(i);
            } else {
                if(!s.empty()) {
                    char ch = s.top();
                    switch (i) {
                        case '}':
                            if(ch != '{')
                                return false;
                            break;
                        case ']':
                            if(ch != '[')
                                return false;
                            break;
                        case ')':
                            if(ch != '(') 
                                return false;
                            break;
                    }
                    s.pop();
                } else 
                    return false;
            }
        }
        return s.empty();
    }
};
