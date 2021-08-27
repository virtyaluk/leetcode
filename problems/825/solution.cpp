class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        vector<int> pref(122);
        
        for (const int& num: ages) {
            pref[num]++;
        }
        
        for (int i = 1; i < 122; i++) {
            pref[i] += pref[i - 1];
        }
        
        for (const int& age: ages) {
            if (age <= 14) {
                continue;
            }
            
            ans += pref[age] - pref[0.5 * age + 7] - 1;
        }
        
        return ans;
    }
};