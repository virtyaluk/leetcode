class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0,
            n = size(nums),
            i = 0,
            j = 0;
        
        sort(begin(nums), end(nums));
        nums.erase(unique(begin(nums), end(nums)), end(nums));
        
        for (; j < size(nums); j++) {
            if (nums[i] + n <= nums[j]) {
                i++;
            }
        }
        
        return n - j + i;
    }
};