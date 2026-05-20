class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<float, int>> road;
        
        int n = position.size();
        for (int i = 0; i < n; i++) {
            road.push_back({position[i], speed[i]});
        }
        sort(road.rbegin(), road.rend());
        
        stack<float> fleets;

        for (const auto& pair : road) {
            float time = (target - pair.first) / pair.second;
            if (fleets.empty() || time > fleets.top()) {
                fleets.push(time);
            }
        }

        return fleets.size();
    }
};
