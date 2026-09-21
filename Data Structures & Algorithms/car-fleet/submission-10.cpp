class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> fleets;

        vector<pair<int, int>> cars;

        int n = speed.size();
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());

        for (const auto& pair : cars) {
            double time = (double)(target - pair.first) / pair.second;
            if (fleets.empty() || time > fleets.top()) fleets.push(time);
        }

        return fleets.size();
    }
};
