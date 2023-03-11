class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        
        for (int i = 0; i < size(nums); i++) {
            ans.push_back(nums[i][i] == '1' ? '0' : '1');
        }
        
        return ans;
    }
};