class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int ans = 0,
            left = 0,
            blocked = 0;
        
        for (int i = 0; i < size(startTime); i++) {
            ans = max(ans, startTime[i] - left - blocked);
            blocked += endTime[i] - startTime[i];

            if (i >= k) {
                int j = i - k;
                left = endTime[j];
                blocked -= endTime[j] - startTime[j];
            }
        }

        ans = max(ans, eventTime - left - blocked);

        return ans;
    }
};