class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans = 0, flips = 0;
        
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] == flips % 2) {
                if (i > size(nums) - k) {
                    return -1;
                }
                
                flips++;
                ans++;
                nums[i] -= 2;
            }
            
            if (i >= k - 1 and nums[i - k + 1] < 0) {
                flips--;
            }
        }
        
        return ans;
    }
    
    int minKBitFlips1(vector<int>& nums, int k) {
        int ans = 0;
        
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] != 1) {
                if (i + k - 1 >= size(nums)) {
                    return -1;
                }
                
                for (int j = 0; j < k; j++) {
                    nums[i + j] = not nums[i + j];
                }
                
                ans++;
            }
        }
        
        return ans;
    }
};