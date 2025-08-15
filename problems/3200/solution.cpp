class Solution {
private:
    int check(int a, int b) {
        int balls[2] = {a, b};
        int ans = 0;
        
        while (balls[ans % 2] >= (ans + 1)) {
            balls[ans % 2] -= (ans + 1);
            ans++;
        }

        return ans;
    }
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(check(red, blue), check(blue, red));
    }
};