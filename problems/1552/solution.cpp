class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(begin(position), end(position));
        int lo = 0, hi = position.back() - position.front();
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (count(position, mid) >= m) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return lo - 1;
    }
    
    int count(vector<int>& position, int d) {
        int ans = 1, cur = position[0];
        
        for (int i = 1; i < size(position); i++) {
            if (position[i] - cur >= d) {
                ans++;
                cur = position[i];
            }
        }
        
        return ans;
    }
};