class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int ans = 0;
        
        for (int i = 0; i < size(hours); i++) {
            for (int j = i + 1; j < size(hours); j++) {
                ans += (hours[i] + hours[j]) % 24 == 0;
            }
        }
        
        return ans;
    }
};