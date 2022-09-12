class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, alt = 0;
        
        for (int& num: gain) {
            alt += num;
            ans = max(ans, alt);
        }
        
        return ans;
    }
};