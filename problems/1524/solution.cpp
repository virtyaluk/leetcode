const int MOD = 1e9 + 7;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;

        for (int i = 0, sum = 0, odd = 0, even = 1; i < size(arr); i++) {
            sum += arr[i];

            if (sum % 2 == 0) {
                ans += odd;
                even++;
            } else {
                ans += even;
                odd++;
            }

            ans %= MOD;
        }

        return ans;
    }
};