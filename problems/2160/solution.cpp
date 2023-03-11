class Solution {
public:
    int minimumSum(int num) {
        string snum = to_string(num);
        
        sort(begin(snum), end(snum));
        
        return (snum[0] - '0') * 10 + (snum[2] - '0') + (snum[1] - '0') * 10 + (snum[3] - '0');
    }
};