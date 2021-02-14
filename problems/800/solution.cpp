class Solution {
public:
    string similarRGB(string color) {
        string ans = "#";
        auto findTarget = [](string cs) {
            int num = stoi(cs, nullptr, 16),
                x = round(num * 1.0 / 17);
            string ans;
            ans = x > 9 ? 'a' + x - 10 : '0' + x;
            
            return ans + ans;
        };
        
        for (int i = 1; i < 6; i += 2) {
            ans += findTarget(color.substr(i, 2));
        }
        
        return ans;
    }
};