class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0, n = size(garbage), m = size(travel);
        vector<int> pref = {0};
        
        for (const int& t: travel) {
            pref.push_back(pref.back() + t);
        }
        
        for (int i = n - 1, seenG = 0, seenP = 0, seenM = 0; i >= 0; i--) {
            ans += size(garbage[i]);
            
            for (const char& ch: garbage[i]) {
                if (ch == 'G' and not seenG) {
                    seenG = true;
                    ans += pref[i];
                } else if (ch == 'P' and not seenP) {
                    seenP = true;
                    ans += pref[i];
                } else if (ch == 'M' and not seenM) {
                    seenM = true;
                    ans += pref[i];
                }
            }
        }
        
        return ans;
    }
};