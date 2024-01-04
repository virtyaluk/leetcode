class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        map<int, int> m;
        
        for (auto item: nums1) {
            m[item.front()] += item.back();
        }
        
        for (auto item: nums2) {
            m[item.front()] += item.back();
        }

        for (auto [id, val]: m) {
            ans.push_back({id, val});
        }
        
        return ans;
    }
};