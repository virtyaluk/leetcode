class Solution {
public:
    bool checkTwoChessboards(string a, string b) {
        return (a.front() - 'a' + a.back() - '0') % 2 == (b.front() - 'a' + b.back() - '0') % 2;
    }
};