class MinStack {
    private:
        stack<int> pilha;
        stack<int> aux;

    public:
        MinStack() { aux.push(INT_MAX); };

        void push (int val) {
            pilha.push(val);
            aux.push(min(aux.top(), val));
        }

        void pop () {
            pilha.pop();
            aux.pop();
        }

        int top() {
            return pilha.top();
        }

        int getMin () {
            return aux.top();
        }
};