class Solution {
private:
    unordered_set<string> invalid;

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> um;
        
        for (string& a: allowed) {
            um[a.substr(0, 2)].push_back(a[2]);
        }
        
        return dfs(um, bottom, "");
    }
    
    bool dfs(unordered_map<string, vector<char>>& um, string& bottom, string top) {
        if (size(bottom) == 1) {
            return true;
        }
        
        if (invalid.count(bottom)) {
            return false;
        }
        
        if (size(top) == size(bottom) - 1) {
            return dfs(um, top, "");
        }
        
        for (const char& next: um[bottom.substr(size(top), 2)]) {
            if (dfs(um, bottom, top + next)) {
                return true;
            }
        }
        
        invalid.insert(bottom);
        
        return false;
    }
};