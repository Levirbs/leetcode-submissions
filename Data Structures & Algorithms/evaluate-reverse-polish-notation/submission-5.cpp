class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> pilha;

        for (const string& c : tokens) {
            if (c == "+" || c == "-" || c == "/" || c == "*") {
                int second = pilha.top(); pilha.pop();
                int first = pilha.top(); pilha.pop();

                if (c == "+") pilha.push(first + second);
                else if (c == "-") pilha.push(first - second);
                else if (c == "/") pilha.push(first / second);
                else if (c == "*") pilha.push(first * second);
            } else {
                pilha.push(stoi(c));
            }
        }

        return pilha.top();
    }
};
