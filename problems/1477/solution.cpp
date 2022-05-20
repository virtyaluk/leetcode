class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = size(arr), oneMinLen = INT_MAX / 2, twoMinLen = INT_MAX / 2;
        vector<int> minLenSeenSoFar(n + 1, INT_MAX / 2);
        
        for (int left = 0, right = 0, sum = 0; left < n;) {
            if (sum == target) {
                oneMinLen = min(oneMinLen, right - left);
                twoMinLen = min(twoMinLen, right - left + minLenSeenSoFar[left]);
            }
            
            if (sum >= target or right == n) {
                sum -= arr[left++];
            } else {
                minLenSeenSoFar[right] = oneMinLen;
                sum += arr[right++];
            }
        }
        
        return twoMinLen >= INT_MAX / 2 ? -1 : twoMinLen;
    }
};