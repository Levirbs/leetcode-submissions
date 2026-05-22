class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       stack<pair<int, int>> pilha;
       
       int n = temperatures.size();
       vector<int> res(n, 0);

       for (int i = 0; i < n; i++) {
            int curr = temperatures[i];
            while (!pilha.empty() && curr > pilha.top().first) {
                int i_topo = pilha.top().second;
                res[i_topo] = i - i_topo;
                pilha.pop();
            }
            pilha.push({curr, i});
       }
       return res;
    }
};
