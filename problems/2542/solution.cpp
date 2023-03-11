class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0, i = 0, n = size(nums1), curSum = 0;
        vector<pair<int, int>> vpii;
        priority_queue<int, vector<int>, greater<>> pq;
        
        for (int i = 0; i < n; i++) {
            vpii.push_back({nums2[i], nums1[i]});
        }
        
        sort(rbegin(vpii), rend(vpii));
        
        for (; i < k; i++) {
            pq.push(vpii[i].second);
            curSum += vpii[i].second;
        }
        
        ans = max(ans, curSum * vpii[i - 1].first);
        
        for (; i < n; i++) {
            pq.push(vpii[i].second);
            curSum += vpii[i].second;
            curSum -= pq.top();
            pq.pop();
            ans = max(ans, curSum * vpii[i].first);
        }
        
        return ans;
    }
};