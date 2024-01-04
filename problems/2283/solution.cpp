class Solution {
public:
    bool digitCount(string num) {
        unordered_map<char, int> um;
        
        for (int i = 0; i < size(num); i++) {
            um[num[i]]++;
        }
        
        for (int i = 0; i < size(num); i++) {
            char ch = i + '0';
            
            if (um[ch] != num[i] - '0') {
                return false;
            }
        }
        
        return true;
    }
};