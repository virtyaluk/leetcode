class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        if (size(nums) == k) {
            return nums;
        }
        
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        vector<pair<int,int>> vp;
        
        for (int i = 0; i < size(nums); i++) {
            pq.push({nums[i], i});
        }
        
        while (k--) {
            vp.push_back({pq.top().second, pq.top().first});
            pq.pop();
        }
        
        sort(begin(vp), end(vp));
        
        for(auto [_, num]: vp) {
            ans.push_back(num);
        }
        
        return ans;
    }
};