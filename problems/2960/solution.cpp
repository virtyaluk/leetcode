class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0,
            dec = 0;
        
        for (int num: batteryPercentages) {
            num = max(0, num - dec);
            
            if (num > 0) {
                ans++;
                dec++;
            }
        }
        
        return ans;
    }
};