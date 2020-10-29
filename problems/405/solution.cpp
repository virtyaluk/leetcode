class Solution {
public:
    string toHex(int num) {
        stringstream ss;
        ss << setbase(16) << num;
        
        return ss.str();
    }
};