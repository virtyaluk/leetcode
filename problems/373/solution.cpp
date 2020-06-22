class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int m = size(nums1), n = size(nums2);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        
        for (int i = 0; i < m; i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }
        
        while (size(ans) < k and not empty(pq)) {
            auto [sum, idx] = pq.top();
            auto [i, j] = idx;
            pq.pop();
            
            ans.push_back({nums1[i], nums2[j]});
            
            if (j + 1 < n) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }
        
        return ans;
    }
};