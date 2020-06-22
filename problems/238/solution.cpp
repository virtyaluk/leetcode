class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = size(nums);
        vector<int> ans(n, 1);
        
        for (int prev = 1, i = 0; i < n; i++) {
            ans[i] = prev;
            prev *= nums[i];
        }
        
        for (int prev = 1, i = n - 1; i >= 0; i--) {
            ans[i] *= prev;
            prev *= nums[i];
        }
        
        return ans;
    }
};

/*

1  2  3  4
1  1  2  6
24 12 4  1
24 12 8  6

*/