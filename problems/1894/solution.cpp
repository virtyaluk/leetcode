class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum = 0;
        
        for (const int& num: chalk) {
            sum += num;
        }
        
        k %= sum;
        
        for (int i = 0; i < size(chalk); i++) {
            if (k < chalk[i]) {
                return i;
            }
            
            k -= chalk[i];
        }
        
        return 0;
    }
};