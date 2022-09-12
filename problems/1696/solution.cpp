class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int ans = nums[0];
        deque<pair<int, int>> dq;
        
        dq.push_back({ans, 0});
        
        for (int i = 1; i < nums.size(); i++) {
            while (not dq.empty() and dq.front().second < i - k) {
                dq.pop_front();
            }
            
            ans = nums[i] + dq.front().first;
            
            while (not dq.empty() and ans >= dq.back().first) {
                dq.pop_back();
            }
            
            dq.push_back({ans, i});
        }
        
        return ans;
    }
    
    int maxResult1(vector<int>& nums, int k) {
        int ans = INT_MIN, n = nums.size();
        priority_queue<pair<int, int>> pq;
        
        for (int i = 0; i < n; i++) {
            while (not pq.empty() and pq.top().second < i - k) {
                pq.pop();
            }
            
            ans = nums[i] + (pq.empty() ? 0 : pq.top().first);
            pq.push({ans, i});
        }
    
        return ans;
    }
};