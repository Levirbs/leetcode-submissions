class MinStack {
private:
    stack<int> standard;
    stack<int> minStack;

public:
    MinStack() {}
    
    void push(int val) {
        standard.push(val);

        if (minStack.empty()) {
            minStack.push(val);
        } else {
            minStack.push(min(val, minStack.top()));
        }
    }
    
    void pop() {
        standard.pop();
        minStack.pop();
    }
    
    int top() {
        return standard.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
