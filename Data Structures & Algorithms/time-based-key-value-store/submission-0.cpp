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

        const vector<pair<string, int>>& lista = mapa[key];
        
        int n = lista.size();
        if (n > 0) {
            int l = 0;
            int r = n - 1;

            while (l <= r) {
                int m = l + (r - l) / 2;

                const pair<string, int> el = lista[m];
                if (el.second == timestamp) return el.first;

                if (el.second > timestamp) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            
            return r >= 0 ? lista[r].first : "";

        }
        
        return "";
    }
};