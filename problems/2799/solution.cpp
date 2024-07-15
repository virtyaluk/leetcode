class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> unique(begin(nums), end(nums));
        unordered_map<int, int> freq;
        
        for (int lo = 0, hi = 0, k = size(unique); hi < size(nums); hi++) {
            k -= freq[nums[hi]]++ == 0;
            
            while (k == 0) {
                k += --freq[nums[lo++]] == 0;
            }
            
            ans += lo;
        }
        
        return ans;
    }
};