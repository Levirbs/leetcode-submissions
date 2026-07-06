class MinStack {
private:
    stack<int> pilha;
    stack<int> minStack;
public:
    MinStack() {}
    
    void push(int val) {
        pilha.push(val);

        if (!minStack.empty()) {
            minStack.push(min(minStack.top(), val));
        } else {
            minStack.push(val);
        }
    }
    
    void pop() {
        pilha.pop();
        minStack.pop();
    }
    
    int top() {
        return pilha.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
