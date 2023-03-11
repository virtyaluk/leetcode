class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        int ans = 0, spottedOne = 0;
        
        for (string& str: words) {
            if (str.front() == str.back()) {
                if (freq[str]) {
                    ans += 4;
                    freq[str]--;
                    spottedOne--;
                } else {
                    freq[str]++;
                    spottedOne++;
                }
            } else {
                string drow;
                
                drow.push_back(str.back());
                drow.push_back(str.front());
                
                if (freq[drow]) {
                    ans += 4;
                    freq[drow]--;
                } else {
                    freq[str]++;
                }
            }
        }
        
        if (spottedOne) {
            ans += 2;
        }
        
        return ans;
    }
};