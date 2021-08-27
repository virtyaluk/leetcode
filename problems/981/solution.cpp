class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (not store.count(key)) {
            return "";
        }
        
        if (store[key][0].first > timestamp) {
            return "";
        }
        
        if (store[key].back().first <= timestamp) {
            return store[key].back().second;
        }
        
        int lo = 0, hi = size(store[key]) - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (store[key][mid].first <= timestamp) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return store[key][lo - 1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */