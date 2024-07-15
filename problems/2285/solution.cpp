class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        unordered_map<int, int> um, um2;
        vector<pair<int, int>> vp;
        
        for (const vector<int>& r: roads) {
            um[r[0]]++;
            um[r[1]]++;
        }
        
        for (auto [city, freq]: um) {
            vp.push_back({freq, city});
        }
        
        for (int i = 0; i < max(0, n - (int) size(um)); i++) {
            vp.push_back({0, n + i + 1});
        }
        
        sort(begin(vp), end(vp));
        
        for (int i = 0; i < size(vp); i++) {
            um2[vp[i].second] = i + 1;
        }
        
        for (const vector<int>& r: roads) {
            ans += um2[r[0]];
            ans += um2[r[1]];
        }
        
        return ans;
    }
};