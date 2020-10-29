class Solution {
public:
    int findComplement(int num) {
        return num ^ (~0u >> __builtin_clz(num));
    }
};