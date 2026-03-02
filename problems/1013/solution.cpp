class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(begin(arr), end(arr), 0),
            ans = 0;
        
        if (sum % 3 != 0) {
            return false;
        }
        
        for (int i = 0, j = 0; i < 3; i++) {
            int s = 0;

            while (j < size(arr)) {
                s += arr[j++];

                if (s == sum / 3) {
                    ans++;
                    
                    break;
                }
            }
        }

        return ans == 3;
    }
};