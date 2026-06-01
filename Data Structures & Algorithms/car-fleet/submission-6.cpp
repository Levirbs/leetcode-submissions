class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();

        vector<pair<int, int>> road(n);

        for (int i = 0; i < n; i++) {
            road[i] = {position[i], speed[i]};
        }

        sort(road.rbegin(), road.rend());

        stack<double> fleets;
        int res = 0;

        for (const auto& pair : road) {
            double time = (double)(target - pair.first) / pair.second;

            if (fleets.empty() || time > fleets.top()) {
                res++;
                fleets.push(time);
            }
        }
        return res;
    }
};
