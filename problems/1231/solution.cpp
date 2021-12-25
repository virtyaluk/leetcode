class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int people = k + 1,
            lo = *min_element(begin(sweetness), end(sweetness)),
            hi = accumulate(begin(sweetness), end(sweetness), 0) / people;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2,
                curSweet = 0,
                curPeople = 0;
            
            for (const int& s: sweetness) {
                curSweet += s;
                
                if (curSweet >= mid) {
                    curSweet = 0;
                    curPeople++;
                }
            }
            
            if (curPeople >= people) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return hi;
    }
};