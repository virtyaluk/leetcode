class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        int n = size(state),
            time = 0,
            i = 0,
            dir = 1;
        vector<int> ans(n);
        queue<int> arr[2];
        
        while (n - i + size(arr[0]) + size(arr[1])) {
            while (i < n && arrival[i] <= time) {
                arr[state[i]].push(i++);
            }
            
            dir = empty(arr[0]) ? 1 : empty(arr[1]) ? 0 : dir;
            
            if (not empty(arr[dir])) {
                ans[arr[dir].front()] = time;
                arr[dir].pop();
            }
            
            time++;
        }
        
        return ans;
    }
};