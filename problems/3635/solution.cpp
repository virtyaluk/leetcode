class Solution {
private:
    int solve(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        int f1 = INT_MAX,
            f2 = INT_MAX;
        
        for (int i = 0; i < size(a); i++) {
            f1 = min(f1, a[i] + b[i]);
        }

        for (int i = 0; i < size(c); i++) {
            f2 = min(f2, max(c[i], f1) + d[i]);
        }

        return f2;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landWater = solve(landStartTime, landDuration, waterStartTime, waterDuration),
            waterLand = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        
        return min(landWater, waterLand);
    }
};