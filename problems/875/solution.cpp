class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1,
            hi = *max_element(begin(piles), end(piles));
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (check(piles, h, mid)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
    
    bool check(const vector<int>& piles, const int& h, const int& k) {
        long long int times = 0;
        
        for (const int& pile: piles) {
            times += (pile - 1) / k + 1;
        }
        
        return times <= h;
    }
};