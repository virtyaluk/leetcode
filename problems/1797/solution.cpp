class AuthenticationManager {
private:
    int ttl;
    unordered_map<string, int> store;
    set<pair<int, string>> time;
    
    void clean(int currentTime) {
        while (not empty(time) and begin(time)->first <= currentTime) {
            store.erase(begin(time)->second);
            time.erase(begin(time));
        }
    }
public:
    AuthenticationManager(int timeToLive): ttl{timeToLive} {
        
    }
    
    void generate(string tokenId, int currentTime) {
        time.insert({currentTime + ttl, tokenId});
        store[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        clean(currentTime);
        
        auto it = store.find(tokenId);
        
        if (it != end(store)) {
            time.erase({it->second, it->first});
            store[tokenId] = currentTime + ttl;
            time.insert({store[tokenId], tokenId});
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        clean(currentTime);
        
        return size(time);
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */