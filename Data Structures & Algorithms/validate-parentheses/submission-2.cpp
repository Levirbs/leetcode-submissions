class Solution {
public:
    bool isValid(string s) {
        stack<char> pilha;

        for (char c : s) {
            if (c == '(') pilha.push(')');
            else if (c == '{') pilha.push('}');
            else if (c == '[') pilha.push(']');

            else {
                if (pilha.empty() || c != pilha.top()) return false;

                pilha.pop();
            }
        }
        return pilha.empty();
    }
};
