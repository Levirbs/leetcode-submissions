class Solution {
public:
    bool isValid(string s) {
        stack<char> pilha;

        for (const char& c : s) {
            if (c == '{') pilha.push('}');
            else if (c == '(') pilha.push(')');
            else if (c == '[') pilha.push(']');

            else {
                if (!pilha.empty() && c == pilha.top()) pilha.pop();
                else return false;
            }
       }
       return pilha.empty();
    }
};
