class Solution {
public:
    bool isValid(string s) {
        stack<char> pilha;
        int n = s.length();

        for (char c : s) {
            if (c == '{' || c == '[' || c == '(') {
                pilha.push(c);
            } else {
                if (pilha.empty()) return false;
                char top = pilha.top();

                if ((top == '{' && c == '}') || (top == '[' && c == ']') || (top == '(' && c == ')')) {
                    pilha.pop();
                } else {
                    return false;
                }
            }
        }
        return pilha.empty();
    }
};
