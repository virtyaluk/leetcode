class Solution {
public:
    long long numberOfWays(string s) {
        long long int ans = 0,
            n = size(s);
        vector<int> zerosLeft(n),
            zerosRight(n);
        
        for (int i = 1; i < n; i++) {
            zerosLeft[i] = zerosLeft[i - 1];
            
            if (s[i - 1] == '0') {
                zerosLeft[i]++;
            }
        }
        
        for (int i = n - 2; i >= 0; i--) {
            zerosRight[i] = zerosRight[i + 1];
            
            if (s[i + 1] == '0') {
                zerosRight[i]++;
            }
        }
        
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '1') {
                ans += zerosLeft[i] * zerosRight[i];
            } else {
                int left = i - zerosLeft[i],
                    right = n - i - 1 - zerosRight[i];
                ans += left * right;
            }
        }
        
        return ans;
    }
};