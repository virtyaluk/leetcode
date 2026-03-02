class Solution {
public:
    int maxOperations(string s) {
        int count1 = 0,
            ans = 0;
        
        for (int i = 0; i < size(s); i++) {
            if (s[i] == '0') {
                while ((i + 1) < size(s) and s[i + 1] == '0') {
                    i++;
                }

                ans += count1;
            } else {
                count1++;
            }
        }

        return ans;
    }
};