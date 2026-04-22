class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> pilha;

        int n = temperatures.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            int t = temperatures[i];

            while (!pilha.empty() && t > pilha.top().first) {
                auto topo = pilha.top();
                pilha.pop();
                res[topo.second] = i - topo.second;
            }
            pilha.push({t, i});
        }
        return res;
    }
};
