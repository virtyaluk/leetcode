class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        
        for (const string& str: strs) {
            if (*max_element(begin(str), end(str)) >= 'A') {
                ans = max(ans, (int) size(str));
            } else {
                ans = max(ans, stoi(str));
            }
        }
        
        return ans;
    }
};