class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area),
            l = 0;
        
        while (area % w != 0) {
            w--;
        }
        
        l = area / w;
        
        return {l, w};
    }
};