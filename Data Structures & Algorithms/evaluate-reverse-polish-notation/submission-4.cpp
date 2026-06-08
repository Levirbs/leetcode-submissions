class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> pilha;

        for (const string& c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int second = pilha.top(); pilha.pop();
                int first = pilha.top(); pilha.pop();
                int num;

                switch (c[0]) {
                    case '+': num = first + second; break;
                    case '-': num = first - second; break;
                    case '*': num = first * second; break;
                    case '/': num = first / second; break;
                }

                pilha.push(num);
            } else {
                pilha.push(stoi(c));
            }
        }

        return pilha.top();
    }
};
