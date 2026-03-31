class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i : s) {
            switch (i) {
                case '[':
                case '{':
                case '(':
                    st.push(i);
            } 
            char ch;
              switch (i) {
                case ']':
                    if(st.empty())
                        return false;
                    ch = st.top();
                    if(ch != '[')
                        return false;
                    st.pop();
                    break;
                case '}':
                    if(st.empty())
                        return false;
                    ch = st.top();
                    if(ch != '{')
                        return false;
                    st.pop();
                    break;
                case ')':
                    if(st.empty())
                        return false;
                    ch = st.top();
                    if(ch != '(')
                        return false;
                    st.pop();
                    break;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};
