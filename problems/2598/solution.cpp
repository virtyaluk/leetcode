class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> vi(value);
        int ans = 0;

        for (const int& num: nums) {
            int v = (num % value + value) % value;
            vi[v]++;
        }

        while (vi[ans % value] > 0) {
            vi[ans % value]--;
            ans++;
        }

        return ans;
    }
};