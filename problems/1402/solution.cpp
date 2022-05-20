class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int ans = 0, sum = 0, cur = 0;
        
        sort(satisfaction.begin(), satisfaction.end());
        
        for (int i = satisfaction.size() - 1; i >= 0; i--) {
            sum += satisfaction[i];
            cur += sum;
            ans = max(ans, cur);
        }
        
        return ans;
    }
};