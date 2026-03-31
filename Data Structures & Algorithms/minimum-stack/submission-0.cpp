class MinStack {
     stack<int> stack1;
     stack<int> minStack;
public:
    MinStack() {}
    
    void push(int val) {
        int minVal = min(val,minStack.empty() ? val : minStack.top());
        minStack.push(minVal);
        stack1.push(val);
    }
    
    void pop() {
        minStack.pop();
        stack1.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
