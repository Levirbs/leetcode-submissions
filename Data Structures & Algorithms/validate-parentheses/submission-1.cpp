class Solution {
public:
    bool isValid(string s) {
        stack<char> pilha;
        int n = s.length();

        unordered_map<char, char> abrefecha = {
            {'}', '{'},
            {']', '['},
            {')', '('}
        };

        for (char c : s) {
            if (!abrefecha.count(c)) {
                pilha.push(c);
            } else {
                if (pilha.empty()) return false;
                char top = pilha.top();

                if (top == abrefecha[c]) {
                    pilha.pop();
                } else {
                    return false;
                }
            }
        }
        return pilha.empty();
    }
};
