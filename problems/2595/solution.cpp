class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        bool flag = false;
        
        while (n) {
            ans[flag] += n & 1;
            flag = !flag;
            n >>= 1;
        }
        
        return ans;
    }
};