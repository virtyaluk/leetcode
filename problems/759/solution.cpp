/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        int curLoad = 0, prevLoad = 0, start = INT_MIN, end = INT_MIN;
        map<int, int> m;
        vector<Interval> ans;
        
        for (const vector<Interval>& ints: schedule) {
            for (const Interval& i: ints) {
                m[i.start]++;
                m[i.end]--;
            }
        }
        
        for (auto [time, load]: m) {
            prevLoad = curLoad;
            curLoad += load;
            
            if (prevLoad > curLoad && curLoad == 0) {
                start = time;
            } else if (prevLoad == 0 && curLoad > prevLoad) {
                end = time;
            }
            
            if (end != INT_MIN && start != INT_MIN && end - start > 0) {
                ans.push_back(Interval(start, end));
                end = start = INT_MIN;
            }
        }
        
        return ans;
    }
};