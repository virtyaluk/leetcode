class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int best1Start = 0,
            curWinSum1 = 0,
            curWinSum2 = 0,
            curWinSum3 = 0;
        vector<int> best2Start = {0, k},
            best3Start = {0, k, k * 2};

        for (int i = 0; i < k; i++) {
            curWinSum1 += nums[i];
        }

        for (int i = k; i < k * 2; i++) {
            curWinSum2 += nums[i];
        }

        for (int i = k * 2; i < k * 3; i++) {
            curWinSum2 += nums[i];
        }

        int best1Sum = curWinSum1,
            best2Sum = curWinSum1 + curWinSum2,
            best3Sum = curWinSum1 + curWinSum2 + curWinSum3,
            start1Idx = 1,
            start2Idx = k + 1,
            start3Idx = k * 2 + 1;

        while (start3Idx <= size(nums) - k) {
            curWinSum1 = curWinSum1 - nums[start1Idx - 1] + nums[start1Idx + k - 1];
            curWinSum2 = curWinSum2 - nums[start2Idx - 1] + nums[start2Idx + k - 1];
            curWinSum3 = curWinSum3 - nums[start3Idx - 1] + nums[start3Idx + k - 1];

            if (curWinSum1 > best1Sum) {
                best1Start = start1Idx;
                best1Sum = curWinSum1;
            }

            if (curWinSum2 + best1Sum > best2Sum) {
                best2Start[0] = best1Start;
                best2Start[1] = start2Idx;
                best2Sum = curWinSum2 + best1Sum;
            }

            if (curWinSum3 + best2Sum > best3Sum) {
                best3Start[0] = best2Start[0];
                best3Start[1] = best2Start[1];
                best3Start[2] = start3Idx;
                best3Sum = curWinSum3 + best2Sum;
            }

            start1Idx++;
            start2Idx++;
            start3Idx++;
        }

        return best3Start;
    }
};