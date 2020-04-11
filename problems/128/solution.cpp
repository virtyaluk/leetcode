class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> um;
        
        for (const int& num: nums) {
            um[num]++;
        }
        
        for (const int& num: nums) {
            int cur = 1, num2 = num + 1;
            
            um.erase(num);
            
            while (um.count(num2)) {
                cur++;
                um.erase(num2);
                num2++;
            }
            
            num2 = num - 1;
            
            while (um.count(num2)) {
                cur++;
                um.erase(num2);
                num2--;
            }
            
            ans = max(ans, cur);
        }
        
        return ans;
    }
};