class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (const char& c : tasks) count[c - 'A']++;

        priority_queue<int> maxHeap;
        for (const int& cnt : count) if (cnt > 0) maxHeap.push(cnt);

        queue<pair<int, int>> fila;
        int time = 0;
        while (!maxHeap.empty() || !fila.empty()) {
            time++;

            if (!maxHeap.empty()) {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();

                if (cnt > 0) fila.push({cnt, time + n});

            } else {
                time = fila.front().second;
            }

            if (!fila.empty() && fila.front().second == time) {
                maxHeap.push(fila.front().first); fila.pop();
            }
        }
        
        return time;
    }
};
