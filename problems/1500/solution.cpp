class FileSharing {
private:
    unordered_map<int, vector<int>> users;
    vector<set<int>> chunks;
    set<int> unusedIds;
    int maxId = 1;

public:
    FileSharing(int m): chunks(m + 1) {
        
    }
    
    int join(vector<int> ownedChunks) {
        int id = -1;
        
        if (empty(unusedIds)) {
            id = maxId++;
        } else {
            id = *begin(unusedIds);
            unusedIds.erase(begin(unusedIds));
        }
        
        users[id] = ownedChunks;
        
        for (const int& chunk: ownedChunks) {
            chunks[chunk].insert(id);
        }
        
        return id;
    }
    
    void leave(int userID) {
        unusedIds.insert(userID);
        
        for (const int& chunk: users[userID]) {
            chunks[chunk].erase(userID);
        }
        
        users[userID].clear();
    }
    
    vector<int> request(int userID, int chunkID) {
        users[userID].push_back(chunkID);
        
        auto& ids = chunks[chunkID];
        
        if (empty(ids)) {
            return {};
        }
        
        vector<int> ans = {begin(ids), end(ids)};
        
        ids.insert(userID);
        
        return ans;
    }
};

/**
 * Your FileSharing object will be instantiated and called as such:
 * FileSharing* obj = new FileSharing(m);
 * int param_1 = obj->join(ownedChunks);
 * obj->leave(userID);
 * vector<int> param_3 = obj->request(userID,chunkID);
 */