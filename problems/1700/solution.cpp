class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int s[2] = {0, 0},
            n = size(students),
            i = 0;
        
        for (const int& ns: students) {
            s[ns]++;
        }
        
        for (; i < n and s[sandwiches[i]] > 0; i++) {
            s[sandwiches[i]]--;
        }
        
        return n - i;
    }
};