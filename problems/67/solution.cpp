class Solution {
public:
    string addBinary(string a, string b) {
        int an = a.size() - 1, bn = b.size() - 1;
        string res = "";
        bool carry = false;
        
        while (an >= 0 || bn >= 0 || carry) {
            int nch = carry ? 1 : 0;
            nch += an >= 0 && a[an] == '1' ? 1 : 0;
            nch += bn >= 0 && b[bn] == '1' ? 1 : 0;
            an--;
            bn--;
            carry = nch >= 2;
            nch %= 2;
            res = to_string(nch) + res;
        }
        
        return res;
    }
};