class MinStack {
private:
    stack<int> pilha;
    stack<int> auxMin;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        pilha.push(val);
        if (!auxMin.empty()) {
            auxMin.push(min(auxMin.top(), val));
        } else {
            auxMin.push(val);
        }
    }
    
    void pop() {
        pilha.pop();
        auxMin.pop();
    }
    
    int top() {
        return pilha.top();
    }
    
    int getMin() {
        return auxMin.top();
    }
};
