class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int ans = 0;
        
        for (int i = 0, right = 0; i < size(flips); i++) {
            right = max(right, flips[i]);
            ans += right == i + 1;
        }
        
        return ans;
    }
};