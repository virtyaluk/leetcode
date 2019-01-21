class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = size(nums);
        vector<vector<int>> ans;
        // vector<int> candidate(begin(nums), end(nums));
        function<void(int)> backtrack;
        
        backtrack = [&](int i) {
            if (i == n) {
                ans.push_back(nums);
                return;
            }
            
            for (int j = i; j < n; j++) {
                swap(nums[i], nums[j]);
                
                backtrack(i + 1);
                
                swap(nums[i], nums[j]);
            }
        };
        
        backtrack(0);
        
        return ans;
    }
    
    vector<vector<int>> permute1(vector<int>& nums) {
        int n = size(nums);
        vector<vector<int>> ans;
        vector<int> candidate;
        vector<bool> seen(n);
        function<void()> backtrack;
        
        backtrack = [&]() {
            if (size(candidate) == n) {
                ans.push_back(candidate);
                return;
            }
            
            for (int i = 0; i < n; i++) {
                if (seen[i]) {
                    continue;
                }
                
                seen[i] = true;
                candidate.push_back(nums[i]);
                
                backtrack();
                
                candidate.pop_back();
                seen[i] = false;
            }
        };
        
        backtrack();
        
        return ans;
    }
};