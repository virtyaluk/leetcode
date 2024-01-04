class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> m;
        vector<vector<int>> ans;
        
        for (const vector<int>& item: items1) {
            m[item.front()] += item.back();
        }
        
        for (const vector<int>& item: items2) {
            m[item.front()] += item.back();
        }
        
        for (auto [val, wei]: m) {
            ans.push_back({val, wei});
        }
        
        return ans;
    }
};