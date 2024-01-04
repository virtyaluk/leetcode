class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] == (i % 10)) {
                return i;
            }
        }
        
        return -1;
    }
};