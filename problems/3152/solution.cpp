class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = size(nums);
        vector<bool> ans;
        vector<int> vi(n);
        
        for (int start = 0, end = 0; start < n; start++) {
            end = max(end, start);
            
            while (end < n - 1 and nums[end] % 2 != nums[end + 1] % 2) {
                end++;
            }
            
            vi[start] = end;
        }
        
        for (const vector<int>& q: queries) {
            int from = q.front(),
                to = q.back();
            
            ans.push_back(to <= vi[from]);
        }
        
        return ans;
    }
};