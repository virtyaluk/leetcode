class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0, n = size(nums);
        
        sort(begin(nums), end(nums));
        
        for (int i = 0; i < n - 2; i++) {
            int k = i + 2;
            
            for (int j = i + 1; j < n - 1; j++) {
                while (k < n and nums[i] + nums[j] > nums[k]) {
                    k++;
                }
                
                if (k - j > 0) {
                    ans += k - j - 1;
                }
            }
        }
        
        return ans;
    }
};