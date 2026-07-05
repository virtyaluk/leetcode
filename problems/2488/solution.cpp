class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = size(nums),
            p = -1,
            t = n,
            b = 0,
            ans = 0;
        vector<int> f(2 * n + 1);
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == k) {
                p = i;

                break;
            }
        }

        f[t] = 1;

        for (int i = p - 1; i >= 0; i--) {
            if (nums[i] > k) {
                b++;
            } else {
                b--;
            }

            f[b + t]++;
        }

        b = 0;

        for (int i = p; i < n; i++) {
            if (nums[i] > k) {
                b++;
            } else if (nums[i] < k) {
                b--;
            }

            ans += f[-b + t];
            ans += f[1 - b + t];
        }

        return ans;
    }
};