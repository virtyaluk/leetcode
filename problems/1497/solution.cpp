class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> rem(k);
        
        for (const int& num: arr) {
            rem[(num % k + k) % k]++;
        }
        
        if (rem.front() & 1) {
            return false;
        }
        
        for (int i = 1; i < k; i++) {
            if (rem[i] != rem[k - i]) {
                return false;
            }
        }
        
        return true;
    }
};