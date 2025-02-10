class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans = 0;

        for (const int& num: derived) {
            ans ^= num;
        }

        return not ans;
    }
};