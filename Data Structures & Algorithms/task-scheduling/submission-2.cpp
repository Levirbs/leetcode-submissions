class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (const char& c : tasks) {
            count[c - 'A']++;
        }

        priority_queue<int> maxHeap;
        for (const int& c : count) {
            if (c > 0) maxHeap.push(c);
        }

        int res = 0;
        queue<pair<int, int>> fila;
        while (!maxHeap.empty() || !fila.empty()) {
            res++;

            if (!maxHeap.empty()) {
                int i = maxHeap.top() - 1; maxHeap.pop();
                if (i > 0) {
                    fila.push({i, res + n});
                }

            } else {
                res = fila.front().second;
            }

            if (!fila.empty() && fila.front().second == res) {
                maxHeap.push(fila.front().first); fila.pop();
            }
        }

        return res;
    }
};
