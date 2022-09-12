class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        
        for (int left = 1, right = arr.size(); left - 1 < arr.size(); left++, right--) {
            ans += (left * right + 1) / 2 * arr[left - 1];
        }
        
        return ans;
    }
};