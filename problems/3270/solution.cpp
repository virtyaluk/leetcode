class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int ans = 0;
        string snum1 = format("{:04}", num1),
            snum2 = format("{:04}", num2),
            snum3 = format("{:04}", num3);
        
        for (int i = 0, m = 1; i < 4; i++, m *= 10) {
            ans += min({snum1[3 - i] - '0', snum2[3 - i] - '0', snum3[3 - i] - '0'}) * m;
        }
        
        return ans;
    }
};