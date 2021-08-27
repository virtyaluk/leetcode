class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0, lo = 0, hi = people.size() - 1;
        
        sort(people.begin(), people.end());
        
        while (lo <= hi) {
            if (lo != hi && people[lo] + people[hi] <= limit) {
                lo++;
                hi--;
            } else if (people[lo] > people[hi]) {
                lo++;
            } else {
                hi--;
            }
            
            ans++;
        }
        
        return ans;
    }
};