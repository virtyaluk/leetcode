class Solution {
private:
    bool check(vector<int>& nums, const int p, const int cur) {
        int ans = 0;
        
        for (int i = 0; i < size(nums) - 1; i++) {
            if (nums[i + 1] - nums[i] <= cur) {
                ans++;
                
                if (ans >= p) {
                    return true;
                }
                
                i++;
            }
        }
        
        return false;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (not p) {
            return 0;
        }
        
        sort(begin(nums), end(nums));
        
        int lo = 0,
            hi = nums.back() - nums.front(),
            mid = 0,
            ans = 0;
        
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            
            if (check(nums, p, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            } 
        }
        
        return ans;
    }
};
