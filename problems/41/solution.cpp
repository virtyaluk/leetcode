class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = size(nums), onesCount = 0;
        
        for (const int& num: nums) {
            if (num == 1) {
                onesCount++;
                break;
            }
        }
        
        if (not onesCount) {
            return 1;
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 or nums[i] > n) {
                nums[i] = 1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            
            if (num == n) {
                nums[0] = -abs(nums[0]);
            } else {
                nums[num] = -abs(nums[num]);
            }
        }
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                return i;
            }
        }
        
        if (nums[0] > 0) {
            return n;
        }
        
        return n + 1;
    }
    
    int firstMissingPositive1(vector<int>& nums) {
        int i = 0, end = size(nums);
        
        while (i != end) {
            int num = nums[i];
            
            if (num == i + 1) {
                i++;
            } else if (num <= 0 or num > end or num == nums[num - 1]) {
                swap(nums[i], nums[--end]);
            } else {
                swap(nums[i], nums[num - 1]);
            }
        }
        
        return i + 1;
    }
};