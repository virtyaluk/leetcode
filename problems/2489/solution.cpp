class Solution {
public:
    long long fixedRatio(string s, int num1, int num2) {
        long long int ans = 0;
        unordered_map<int, int> um = {{0, 1}};
        
        for (int i = 0, cnt = 0; i < size(s); i++) {
            if (s[i] == '0') {
                cnt += num2;
            } else {
                cnt -= num1;
            }
            
            ans += um[cnt]++;
        }
        
        return ans;
    }
};