class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX,
            lo = 0,
            bitOr = 0;
        vector<int> freq(32);
        
        for (int i = 0; i < size(nums); i++) {
            bitOr |= nums[i];
            
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j)) {
                    freq[j]++;
                }
            }
            
            while (lo <= i and bitOr >= k) {
                ans = min(ans, i - lo + 1);
                int nextBitOr = 0;
                
                for (int j = 0; j < 32; j++) {
                    if (nums[lo] & (1 << j)) {
                        freq[j]--;
                    }
                    
                    if (freq[j]) {
                        nextBitOr |= (1 << j);
                    }
                }
                
                bitOr = nextBitOr;
                lo++;
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};