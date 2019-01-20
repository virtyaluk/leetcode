class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0, dif = INT_MAX, n = size(nums);
        
        sort(begin(nums), end(nums));
        
        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (abs(target - sum) < abs(dif)) {
                    dif = target - sum;
                    ans = sum;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        
        return ans;
    }
};