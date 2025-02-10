class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;

        for (int num: nums) {
            int x = 0;
            
            while (num) {
                x += num % 10;
                num /= 10;
            }
            
            ans = min(ans, x);
        }
        
        return ans;
    }
};