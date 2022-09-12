class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& l, vector<vector<int>>& f) {
        int ans = INT_MAX;
        unordered_map<int, unordered_set<int>> ms;
        unordered_set<int> s;
        
        for (int i = 0; i < l.size(); i++) {
            for (const int& lang: l[i]) {
                ms[i + 1].insert(lang);
            }
        }
        
        for (const vector<int>& fi: f) {
            int u = fi[0], v = fi[1];
            bool canCom = false;
            
            for (const int& ul: ms[u]) {
                if (ms[v].find(ul) != ms[v].end()) {
                    canCom = true;
                    break;
                }
            }
            
            if (canCom) {
                continue;
            }
            
            s.insert(v);
            s.insert(u);
        }
        
        for (int i = 1; i <= n; i++) {
            int count = 0;
            
            for (const int& u: s) {
                if (ms[u].find(i) == ms[u].end()) {
                    count++;
                }
            }
            
            ans = min(ans, count);
        }
        
        return ans;
    }
};