class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> aux;

        int n = temperatures.size();
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            int curr = temperatures[i];
            while (!aux.empty() && curr > aux.top().first) {
                int i_topo = aux.top().second;
                res[i_topo] = i - i_topo;
                aux.pop();
            }
            aux.push({curr, i});
        }
        return res;
    }
};
