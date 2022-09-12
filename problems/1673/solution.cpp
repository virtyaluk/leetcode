class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        int count = nums.size() - k;
        
        for (int i = 0; i < nums.size(); i++) {
            while (!q.empty() && q.back() > nums[i] && count > 0) {
                q.pop_back();
                count--;
            }
            
            q.push_back(nums[i]);
        }
        
        for (int i = 0; i < k; i++) {
            ans.push_back(q.front());
            q.pop_front();
        }
        
        return ans;
    }
};