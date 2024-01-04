class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        
        for (char a = 'a'; a <= 'z'; a++) {
            for (char b = 'a'; b <= 'z'; b++) {
                if (a == b) {
                    continue;
                }
                
                int acnt = 0,
                    bcnt = 0;
                bool flag = false;
                
                for (const char& ch: s) {
                    acnt += ch == a;
                    bcnt += ch == b;
                    
                    if (bcnt) {
                        ans = max(ans, acnt - bcnt);
                    } else if (flag) {
                        ans = max(ans, acnt - 1);
                    }
                    
                    if (bcnt > acnt) {
                        acnt = bcnt = 0;
                        flag = true;
                    }
                }
            }
        }
        
        return ans;
    }
};