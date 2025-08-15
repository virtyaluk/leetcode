class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        if (s1.front() != s2.front() or s2.front() != s3.front() or s3.front() != s1.front()) {
            return -1;
        }

        int ans = 0,
            len = 0,
            minLen = min({
                size(s1),
                size(s2),
                size(s3)
            });
        
        for (int i = 0; i < minLen; i++) {
            if (s1[i] != s2[i] or s2[i] != s3[i] or s3[i] != s1[i]) {
                break;
            }

            len++;
        }

        ans += size(s1) - len;
        ans += size(s2) - len;
        ans += size(s3) - len;
        
        return ans;
    }
};