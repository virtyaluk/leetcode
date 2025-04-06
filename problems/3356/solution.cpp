class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int ans = 0,
            n = size(nums);
        vector<int> line(n + 1);

        for (int i = 0, sum = 0; i < n; i++) {
            while (sum + line[i] < nums[i]) {
                ans++;

                if (ans > size(q)) {
                    return -1;
                }

                int l = q[ans - 1].front(),
                    r = q[ans - 1][1],
                    v = q[ans - 1].back();
                
                if (r >= i) {
                    line[max(l, i)] += v;
                    line[r + 1] -= v;
                }
            }

            sum += line[i];
        }

        return ans;
    }
};