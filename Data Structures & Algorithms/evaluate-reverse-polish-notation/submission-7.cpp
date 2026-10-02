class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> pilha;

        for (const string& c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int second = pilha.top(); pilha.pop();
                int first = pilha.top(); pilha.pop();

                int res;

                if (c == "+") {
                    res = first + second;

                } else if (c == "-") {
                    res = first - second;

                } else if (c == "*") {
                    res = first * second;

                } else if (c == "/") {
                    res = first / second;

                }

                pilha.push(res);

            } else {
                pilha.push(stoi(c));

            }
        }

        return pilha.empty() ? -1 : pilha.top();
    }
};
