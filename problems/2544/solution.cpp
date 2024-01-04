class Solution {
public:
    int alternateDigitSum(int n) {
        int ans = 0;
        string sn = to_string(n);
        bool flag = true;
        
        for (int i = 0; i < size(sn); i++) {
            ans += (flag ? 1 : -1) * (sn[i] - '0');
            flag = !flag;
        }
        
        return ans;
    }
};