class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> pilha;

        const int n = temperatures.size();
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            while (!pilha.empty() && temperatures[i] > pilha.top().second) {
                int i_topo = pilha.top().first;
                res[i_topo] = i - i_topo;
                pilha.pop();
            }
            pilha.push({i, temperatures[i]});
        }
        return res;
    }
};
