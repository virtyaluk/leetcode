class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, mid = 0, hi = size(nums) - 1;
        
        while (mid <= hi) {
            if (nums[mid] == 0) {
                swap(nums[mid++], nums[lo++]);
            } else if (nums[mid] == 2) {
                swap(nums[mid], nums[hi--]);
            } else {
                mid++;
            }
        }
    }
};