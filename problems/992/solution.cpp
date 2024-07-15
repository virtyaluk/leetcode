class Solution {
private:
    int atMostK(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> um;
        
        for (int lo = 0, hi = 0; hi < size(nums); hi++) {
            if (not um[nums[hi]]++) {
                k--;
            }
            
            while (k < 0) {
                if (not --um[nums[lo++]]) {
                    k++;
                }
            }
            
            ans += hi - lo + 1;
        }
        
        return ans;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};