class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int lo = 0,
            hi = *max_element(begin(arr), end(arr)),
            ans = 0,
            dif = INT_MAX;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2,
                sum = check(arr, mid);
            
            if (abs(target - sum) < dif) {
                dif = abs(target - sum);
                ans = mid;
            } else if (abs(target - sum) == dif) {
                ans = min(ans, mid);
            }
            
            if (sum > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
    
    int check(vector<int>& nums, int val) {
        int ans = 0;
        
        for (const int& num: nums) {
            ans += min(num, val);
        }
        
        return ans;
    }
};