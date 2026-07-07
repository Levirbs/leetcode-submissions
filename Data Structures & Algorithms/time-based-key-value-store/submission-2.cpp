class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> mapa;

public:
    TimeMap() {
        mapa.clear();    
    }
    
    void set(string key, string value, int timestamp) {
        mapa[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (!mapa.count(key)) return "";
        
        auto& lista = mapa[key];

        int l = 0;
        int r = lista.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;

            if (lista[m].second <= timestamp) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return r >= 0 ? lista[r].first : "";
    }
};
