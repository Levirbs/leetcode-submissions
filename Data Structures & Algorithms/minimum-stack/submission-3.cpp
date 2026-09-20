class MinStack {
private:
    stack<int> pilha;
    stack<int> mini;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        pilha.push(val);
        
        if (mini.empty()) {
            mini.push(val);
        } else {
            mini.push(min(mini.top(), val));
        }
    }
    
    void pop() {
        pilha.pop(); mini.pop();
    }
    
    int top() {
        return pilha.top();
    }
    
    int getMin() {
        return mini.top();
    }
};
