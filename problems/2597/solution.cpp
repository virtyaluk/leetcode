class Solution {
private:
    void dfs(const vector<int>& nums, unordered_map<int, int>& cnt, int k, int idx, int& ans) {
        if (idx == size(nums)) {
            ans++;
            
            return;
        }
        
        if (not cnt[nums[idx] - k]) {
            cnt[nums[idx]]++;
            
            dfs(nums, cnt, k, idx + 1, ans);
            
            cnt[nums[idx]]--;
        }
        
        dfs(nums, cnt, k, idx + 1, ans);
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> cnt;
        
        sort(begin(nums), end(nums));
        
        dfs(nums, cnt, k, 0, ans);
        
        return ans - 1;
    }
};