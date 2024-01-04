class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int lo = 0, hi = size(nums) - 1;
        
        while (lo <= hi) {
            string snum = "";
            
            if (lo != hi) {
                snum = to_string(nums[lo]) + to_string(nums[hi]);
            } else {
                snum = to_string(nums[lo]);
            }
            
            lo++;
            hi--;
            ans += stoll(snum);
        }
        
        return ans;
    }
};