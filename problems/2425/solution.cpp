class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0,
            xor2 = 0;

        if (size(nums2) % 2 != 0) {
            for (const int& num: nums1) {
                xor1 ^= num;
            }
        }

        if (size(nums1) % 2 != 0) {
            for (const int& num: nums2) {
                xor2 ^= num;
            }
        }

        return xor1 ^ xor2;
    }
};