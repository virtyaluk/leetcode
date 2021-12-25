class Solution {
public:
    string encode(int num) {
        if (num == 0) {
            return "";
        }
        
        bitset<32> bs(num + 1);
        string ans = bs.to_string();
        
        return ans.substr(ans.find_first_of('1') + 1);
    }
};