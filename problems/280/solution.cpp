class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 0; i < size(nums) - 1; i++) {
            if (i % 2 == 0 and nums[i] > nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            } else if (i % 2 == 1 and nums[i] < nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            }
        }
    }
};