class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans;
        long long score = 0,
            maxSoFar = 0;
        
        for (const int& num: nums) {
            maxSoFar = max(maxSoFar, (long long) num);
            score += num + maxSoFar;
            
            ans.push_back(score);
        }
        
        return ans;
    }
};