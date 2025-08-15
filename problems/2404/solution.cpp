class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int maxFreq = 0,
            ans = INT_MAX;
        unordered_map<int, int> um;

        for (const int& num: nums) {
            if (num % 2 != 0) {
                continue;
            }

            um[num]++;

            if (um[num] == maxFreq) {
                ans = min(ans, num);
            } else if (um[num] > maxFreq) {
                maxFreq = um[num];
                ans = num;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};