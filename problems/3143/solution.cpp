class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int ans = 0;
        map<int, unordered_multiset<char>> m;
        unordered_set<char> seen;
        
        for (int i = 0; i < size(s); i++) {
            m[max(abs(points[i].front()), abs(points[i].back()))].insert(s[i]);
        }
        
        for (auto [dist, tags]: m) {
            unordered_set<char> seenNow;
            
            for (const char& tag: tags) {
                if (seen.count(tag) or seenNow.count(tag)) {
                    return ans;
                }
                
                seenNow.insert(tag);
            }
            
            for (const char& tag: tags) {
                ans++;
                seen.insert(tag);
            }
        }
        
        return ans;
    }
};