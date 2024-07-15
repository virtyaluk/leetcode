class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0; i < size(nums); i++) {
            unordered_set<int> us;
            
            for (int j = i; j < size(nums); j++) {
                us.insert(nums[j]);
                
                ans += pow(size(us), 2);
            }
        }
        
        return ans;
    }
};