class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), longest = 0, ans = 0;
        
        if (n <= 1) {
            return n;
        }
        
        vector<int> lengths(n), counts(n, 1);
        
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                if (nums[i] < nums[j]) {
                    if (lengths[i] >= lengths[j]) {
                        lengths[j] = lengths[i] + 1;
                        counts[j] = counts[i];
                        longest = max(longest, lengths[j]);
                    } else if (lengths[i] + 1 == lengths[j]) {
                        counts[j] += counts[i];
                    }
                }
            }
        }
        
        // for (int len: lengths) {
        //     longest = max(longest, len);
        // }
        
        for (int i = 0; i < n; i++) {
            if (lengths[i] == longest) {
                ans += counts[i];
            }
        }
        
        return ans;
    }
};