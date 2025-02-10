class Solution {
private:
    int countSteps(int n, long pref1, long pref2) {
        int steps = 0;
        
        while (pref1 <= n) {
            steps += min((long) (n + 1), pref2) - pref1;
            pref1 *= 10;
            pref2 *= 10;
        }
        
        return steps;
    }
public:
    int findKthNumber(int n, int k) {
        int ans = 1;
        k--;
        
        while (k > 0) {
            int step = countSteps(n, ans, ans + 1);
            
            if (step <= k) {
                ans++;
                k -= step;
            } else {
                ans *= 10;
                k--;
            }
        }
        
        return ans;
    }
};