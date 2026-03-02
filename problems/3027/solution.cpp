class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;

        sort(begin(points), end(points), [](const vector<int>& a, const vector<int>& b) {
            return a.front() < b.front() or (a.front() == b.front() and a.back() > b.back());
        });

        for (int i = 0; i < size(points) - 1; i++) {
            const vector<int>& pa = points[i];
            int xmin = pa.front() - 1,
                xmax = INT_MAX,
                ymin = INT_MIN,
                ymax = pa.back() + 1;

                for (int j = i + 1; j < size(points); j++) {
                    const vector<int>& pb = points[j];

                    if (pb.front() > xmin and pb.front() < xmax and pb.back() > ymin and pb.back() < ymax) {
                        ans ++;
                        xmin = pb.front();
                        ymin = pb.back();
                    }
                }
        }

        return ans;
    }
};