class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        
        for (const int& num: nums) {
            int x = -1;
            
            for (int i = 0; i <= 1000; i++) {
                if (num == (i | (i + 1))) {
                    x = i;
                    
                    break;
                }
            }
            
            ans.push_back(x);
        }
        
        return ans;
    }
};