class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> pilha;

        for (const string& c : tokens) {
            if (c == "+" || c == "-" || c == "/" || c == "*") {
                int second = pilha.top(); pilha.pop();
                int first = pilha.top(); pilha.pop();
                int result;

                if (c == "+") result = first + second;
                else if (c == "-") result = first - second;
                else if (c == "*") result = first * second;
                else if (c == "/") result = first / second;
                
                pilha.push(result);
            } else {
                pilha.push(stoi(c));
            }
        }

        return pilha.empty() ? -1 : pilha.top();
    }
};
