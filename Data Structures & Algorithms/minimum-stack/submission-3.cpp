class MinStack {
    stack<int> s;
        stack<int> minTop;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        val = min(val, minTop.empty() ? val : minTop.top());
        minTop.push(val);
    }
    
    void pop() {
        s.pop();
        minTop.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
           return minTop.top();     
    }
};
