class Solution {
public:
    int minMaxDifference(int num) {
        string snum = to_string(num),
            min = snum,
            max = snum;
        char ch1 = ' ',
            ch2 = ' ';
        
        for (int i = 0; i < size(snum); i++) {
            if (snum[i] == ch1) {
                min[i] = '0';
            } else if (snum[i] != '0' and ch1 == ' ') {
                ch1 = snum[i];
                min[i] = '0';
            }
            
            if (snum[i] == ch2) {
                max[i] = '9';
            } else if (snum[i] != '9' and ch2 == ' ') {
                ch2 = snum[i];
                max[i] = '9';
            }
        }
        
        return stoi(max) - stoi(min);
    }
};