class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mapa;

public:
    TimeMap() {
        mapa.clear();    
    }
    
    void set(string key, string value, int timestamp) {
        mapa[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mapa.count(key)) {
            auto& values = mapa[key];

            int n = values.size();

            int l = 0;
            int r = n - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                auto& par = values[m];
                int vtime = par.first;

                if (vtime == timestamp) return par.second;

                if (vtime < timestamp) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }

            return r >= 0 ? values[r].second : "";
        }

        return "";
    }
};
