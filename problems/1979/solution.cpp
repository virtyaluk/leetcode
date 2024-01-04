class Solution {
public:
    int findGCD(vector<int>& nums) {
        int m = *min_element(begin(nums), end(nums)),
            M = *max_element(begin(nums), end(nums));
        
        return gcd(m, M);
    }
};