class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> pilha;
        int n = temperatures.size();

        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            int curr = temperatures[i];
            while (!pilha.empty() && temperatures[pilha.top()] < curr) {
                int i_topo = pilha.top();
                res[i_topo] = i - i_topo;
                pilha.pop();
            }
            pilha.push(i);
        }

        return res;
    }
};
