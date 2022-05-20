class Solution {
public:
    int countLargestGroup(int n) {
        int ans = 0, lg = 0;
        map<int, int> m;
        
        for (int i = 1; i <= n; i++) {
            int num = i, sum = 0;
            
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            
            m[sum]++;
            lg = max(lg, m[sum]);
        }
        
        for (auto [_, size]: m) {
            if (size == lg) {
                ans++;
            }
        }
        
        return ans;
    }
};