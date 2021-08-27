class Solution {
private:
    double rad, xc, yc;
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dist{0, 1};
public:
    Solution(double radius, double x_center, double y_center): rad(radius), xc(x_center), yc(y_center) {}
    
    vector<double> randPoint() {
        double r = sqrt(dist(gen)) * rad, theta = dist(gen) * 2 * M_PI;
        double x = r * cos(theta) + xc, y = r * sin(theta) + yc;
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */