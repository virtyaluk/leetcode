class Solution {
private:
    int gcd(int a, int b) {
        if (not a) {
            return b;
        }
        
        return gcd(b % a, a);
    }

public:
    string fractionAddition(string ex) {
        int num = 0,
            denom = 1,
            i = 0;
        vector<string> nums;
        
        if (ex.front() != '-') {
            ex = '+' + ex;
        }
        
        while (i < size(ex)) {
            int j = i + 1;
            
            while (j < size(ex) and ex[j] != '+' and ex[j] != '-') {
                j++;
            }
            
            nums.push_back(ex.substr(i, j - i));
            i = j;
        }
        
        for (int i = 0; i < size(nums); i++) {
            int pos = nums[i].find('/'),
                curNum = stoi(nums[i].substr(1, pos - 1));
            
            if (nums[i][0] == '-') {
                curNum = -curNum;
            }
            
            int curDenom = stoi(nums[i].substr(pos + 1));
            num = num * curDenom + curNum * denom;
            denom = denom * curDenom;
            int _gcd = abs(gcd(num, denom));
            num /= _gcd;
            denom /= _gcd;
        }
        
        return to_string(num) + "/" + to_string(denom);
    }
};