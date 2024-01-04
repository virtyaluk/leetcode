class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> m;
        vector<int> ans;
        
        for (const vector<int>& ar: nums) {
            for (const int& num: ar) {
                m[num]++;
                
                if (m[num] == size(nums)) {
                    ans.push_back(num);
                }
            }
        }
        
        sort(begin(ans), end(ans));
        
        return ans;
    }
};