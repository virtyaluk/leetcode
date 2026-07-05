class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n, 0),
            ans;
        int c = 0;

        for (auto &q: queries) {
            int idx = q.front(),
                color = q[1],
                pre = (idx > 0) ? nums[idx - 1] : 0,
                nex = (idx < n - 1) ? nums[idx + 1] : 0;
            
            if (nums[idx]) {
                c -= (nums[idx] == pre) + (nums[idx] == nex);
            }

            nums[idx] = color;
            c += (nums[idx] == pre) + (nums[idx] == nex);

            ans.push_back(c);
        }

        return ans;
    }
};