class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long totalArea = 0;
        vector<tuple<int, int, int>> events;

        for (const vector<int>& sq: squares) {
            int y = sq[1],
                l = sq[2];
            totalArea += (long long)l * l;
            events.emplace_back(y, l, 1);
            events.emplace_back(y + l, l, -1);
        }

        sort(begin(events), end(events), [](const auto& lhs, const auto& rhs) {
            return get<0>(lhs) < get<0>(rhs);
        });

        double coveredWidth = 0,
            curArea = 0,
            prevHeight = 0;
        
        for (const auto& [y, l, delta]: events) {
            int diff = y - prevHeight;
            double area = coveredWidth * diff;

            if (2ll * (curArea + area) >= totalArea) {
                return prevHeight + (totalArea - 2.0 * curArea) / (2.0 * coveredWidth);
            }

            coveredWidth += delta * l;
            curArea += area;
            prevHeight = y;
        }

        return 0.0;
    }
};