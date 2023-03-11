class SQL {
private:
    unordered_map<string, vector<pair<int, vector<string>>>> store;

public:
    SQL(vector<string>& names, vector<int>& columns) {
        for (const string& name: names) {
            store[name].push_back({0, {}});
        }
    }
    
    void insertRow(string name, vector<string> row) {
        store[name].push_back({
            store[name].back().first + 1,
            row
        });
    }
    
    void deleteRow(string name, int rowId) {
        store[name][rowId].second.clear();
    }
    
    string selectCell(string name, int rowId, int columnId) {
        return store[name][rowId].second[columnId - 1];
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * obj->insertRow(name,row);
 * obj->deleteRow(name,rowId);
 * string param_3 = obj->selectCell(name,rowId,columnId);
 */