class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        if (accumulate(begin(arr), end(arr), 0) % 3 != 0) {
            return false;
        }
        
        unordered_map<int, int> um;
        
        for (const int& num: arr) {
            um[num]++;
        }
        
        if (um[0]) {
            if (um[0] % 2 != 0) {
                return false;
            }
            
            um.erase(0);
        }
        
        for (const auto &[x, _]: um) {
            int num = x;
            
            while (um[num] and num % 2 == 0 and um[num / 2]) {
                num /= 2;
            }
            
            while (um[num] > 0 and um[num * 2]) {
                um[num * 2] -= um[num];
                um[num] = 0;
                num *= 2;
            }
            
            if (um[num]) {
                return false;
            }
        }
        
        return true;
    }
    
    bool canReorderDoubled1(vector<int>& arr) {
        int n = size(arr);
        unordered_map<int, int> freq;
        
        for (const int& num: arr) {
            freq[num]++;
        }
        
        sort(begin(arr), end(arr), [](const int& a, const int& b) {
            return abs(a) < abs(b);
        });
        
        for (const int& num: arr) {
            if (not freq[num]) {
                continue;
            }
            
            if (not freq[num * 2]) {
                return false;
            }
            
            freq[num]--;
            freq[num * 2]--;
        }
        
        return true;
    }
};