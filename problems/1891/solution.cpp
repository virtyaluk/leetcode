class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int lo = 1, hi = *max_element(begin(ribbons), end(ribbons));
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (check(ribbons, mid) >= k) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return not lo ? lo : lo - 1;
    }
    
    int check(const vector<int>& ribbons, int cut) {
        int ans = 0;
        
        for (const int& ribbon: ribbons) {
            ans += ribbon / cut;
        }
        
        return ans;
    }
};