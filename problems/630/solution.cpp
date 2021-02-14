class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int curTotalTime = 0;
        priority_queue<int> pq;
        
        sort(begin(courses), end(courses), [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[1] < rhs[1];
        });
        
        for (const vector<int>& course: courses) {
            int duration = course[0], lastDay = course[1];
            
            if (curTotalTime + duration <= lastDay) {
                // take this course, if we can
                pq.push(duration);
                curTotalTime += duration;
            } else if (not pq.empty() and pq.top() > duration) {
                // replace last taken with this one, if this one is shorter than the last one taken
                curTotalTime = curTotalTime - pq.top() + duration;
                pq.pop();
                pq.push(duration);
            }
        }
        
        return pq.size();
    }
};