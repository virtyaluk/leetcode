class Solution {
public:
    string pushDominoes(string s) {
        int n = size(s), l = -1, r = -1;
        
        for (int i = 0; i <= n; i++) {
            if (i == n or s[i] == 'R') {
                if (r > l) { // R..
                    while (r < i) {
                        s[r++] = 'R';
                    }
                }
                
                r = i;
            } else if (s[i] == 'L') {
                if (l > r or (l == -1 and r == -1)) { // ..L
                    while (++l < i) {
                        s[l] = 'L';
                    }
                } else { // R..L
                    int lo = r + 1, hi = i - 1;
                    
                    while (lo < hi) {
                        s[lo++] = 'R';
                        s[hi--] = 'L';
                    }
                    
                    l = i;
                }
            }
        }
        
        return s;
    }
    
    string pushDominoes1(string dominoes) {
        string ans;
        int n = size(dominoes);
        vector<int> force(n);
        
        for (int i = 0, rightForce = 0; i < n; i++) {
            if (dominoes[i] == 'R') {
                rightForce = n;
            } else if (dominoes[i] == 'L') {
                rightForce = 0;
            } else {
                rightForce = max(0, rightForce - 1);
            }

            force[i] += rightForce;
        }
        
        for (int i = n - 1, leftForce = 0; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                leftForce = n;
            } else if (dominoes[i] == 'R') {
                leftForce = 0;
            } else {
                leftForce = max(0, leftForce - 1);
            }

            force[i] -= leftForce;
        }
        
        for (int i = 0; i < n; i++) {
            if (force[i] == 0) {
                ans.push_back('.');
            } else {
                ans.push_back(force[i] < 0 ? 'L' : 'R');
            }
        }
        
        return ans;
    }
};