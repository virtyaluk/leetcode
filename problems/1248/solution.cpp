class Solution {
private:
    int atMost(vector<int>& nums, int k) {
        int ans = 0;
        
        for (int lo = 0, hi = 0; hi < size(nums); hi++) {
            k -= nums[hi] % 2;
            
            while (k < 0) {
                k += nums[lo++] % 2;
            }
            
            ans += hi - lo + 1;
        }
        
        return ans;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};