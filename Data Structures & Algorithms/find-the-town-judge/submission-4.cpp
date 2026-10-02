class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> people(n + 1, 0);

        for (const auto& par : trust) {
            people[par[0]]--;
            people[par[1]]++;
        }

        for (int i = 0; i < n + 1; i++) {
            if (people[i] == n - 1) return i;
        }

        return -1;
    }
};