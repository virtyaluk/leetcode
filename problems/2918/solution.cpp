class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0,
            sum2 = 0;
        int z1 = 0,
            z2 = 0;
        
        for (const int& num: nums1) {
            sum1 += not num ? 1 : num;
            z1 += not num;
        }

        for (const int& num: nums2) {
            sum2 += not num ? 1 : num;
            z2 += not num;
        }

        if ((not z1 and sum2 > sum1) or (not z2 and sum1 > sum2)) {
            return -1;
        }

        return max(sum1, sum2);
    }
};