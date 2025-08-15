class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return event1.front() <= event2.back() and event2.front() <= event1.back();
    }
};