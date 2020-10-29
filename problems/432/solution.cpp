class AllOne {
private:
    set<pair<int, string>> s;
    unordered_map<string, int> um;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        int was = um[key];
        
        if (was > 0) {
            s.erase({was, key});
            um.erase(key);
        }
        
        was++;
        s.insert({was, key});
        um[key] = was;
    }
    
    void dec(string key) {
        int was = um[key];
        
        s.erase({was, key});
        um.erase(key);
        
        if (was > 1) {
            was--;
            s.insert({was, key});
            um[key] = was;
        }
    }
    
    string getMaxKey() {
        if (empty(s)) {
            return "";
        }
        
        return (*rbegin(s)).second;
    }
    
    string getMinKey() {
        if (empty(s)) {
            return "";
        }
        
        return (*begin(s)).second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */