class ThroneInheritance {
private:
    string king;
    unordered_map<string, pair<bool, vector<string>>> g;
    
    void dfs(string name, vector<string>& ans) {
        if (g[name].first) {
            ans.push_back(name);
        }
        
        for (const string& childName: g[name].second) {
            dfs(childName, ans);
        }
    }
public:
    ThroneInheritance(string kingName) {
        king = kingName;
        g[king] = {true, {}};
    }
    
    void birth(string parentName, string childName) {
        g[parentName].second.push_back(childName);
        g[childName] = {true, {}};
    }
    
    void death(string name) {
        g[name].first = false;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        
        dfs(king, ans);
        
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */