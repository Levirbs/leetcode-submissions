class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> aux;
        int n = temperatures.size();

        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int curr = temperatures[i];
            while (!aux.empty() && curr > temperatures[aux.top()]) {
                int i_topo = aux.top();
                aux.pop();
                res[i_topo] = i - i_topo;
            }
            aux.push(i);
        }

        return res;
    }
};
