class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = size(nums),
            i = 1,
            j,
            k;

        for (; i < n and nums[i - 1] < nums[i]; i++);

        if (i >= n or i == 1) {
            return false;
        }

        j = i;

        for (; j < n and nums[j - 1] > nums[j]; j++);

        if (j >= n or j == i) {
            return false;
        }

        k = j;

        for (; k < n and nums[k - 1] < nums[k]; k++);

        return k >= n;
    }
};