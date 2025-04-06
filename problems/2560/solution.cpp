class Solution {
private:
    bool check(const vector<int>& nums, const int& k, int cap) {
        int ans = 0;

        for (int i = 0; i < size(nums); i++) {
            if (nums[i] <= cap) {
                ans++;
                i++;
            }
        }

        return ans >= k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int lo = *min_element(begin(nums), end(nums)),
            hi = *max_element(begin(nums), end(nums)),
            mid;
        
        while (lo < hi) {
            mid = (lo + hi) / 2;
            
            if (check(nums, k, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};