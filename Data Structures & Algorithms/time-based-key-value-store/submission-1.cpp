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
        if(!mapa.count(key)) return "";

        vector<pair<string, int>>& lista = mapa[key];

        int l = 0;
        int r = lista.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            pair<string, int>& par = lista[m];

            if (par.second == timestamp) return par.first;

            if (timestamp > par.second) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return r > -1 ? lista[r].first : "";
    }
};
