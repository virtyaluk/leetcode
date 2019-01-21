class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = size(nums);
        vector<vector<int>> ans;
        vector<int> candidate;
        unordered_map<int, int> um;
        function<void()> backtrack;
        
        for (const int& num: nums) {
            um[num]++;
        }
        
        backtrack = [&]() {
            if (size(candidate) == n) {
                ans.push_back(candidate);
                return;
            }
            
            for (auto [num, count]: um) {
                if (count) {
                    candidate.push_back(num);
                    um[num]--;
                    
                    backtrack();
                    
                    um[num]++;
                    candidate.pop_back();
                }
            }
        };
        
        backtrack();
        
        return ans;
    }
};