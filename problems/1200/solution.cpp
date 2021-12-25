class Solution {
public:
    vector<vector<int>> minimumAbsDifference1(vector<int>& arr) {
        int minDif = INT_MAX;
        vector<vector<int>> ans;
        
        sort(begin(arr), end(arr));
        
        for (int i = 1; i < size(arr); i++) {
            int curDif = arr[i] - arr[i - 1];
            
            if (curDif == minDif) {
                ans.push_back({arr[i - 1], arr[i]});
            } else if (curDif < minDif) {
                minDif = curDif;
                ans = {{arr[i - 1], arr[i]}};
            }
        }
        
        return ans;
    }
    
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int shift = pow(10, 6),
            minEl = arr.front(),
            maxEl = arr.front();
        vector<uint8_t> line(shift * 2 + 1);
        vector<vector<int>> ans;
        
        for (const int& num: arr) {
            line[num + shift] = 1;
            minEl = min(minEl, num);
            maxEl = max(maxEl, num);
        }
        
        for (int prev = minEl + shift, diff = maxEl - minEl, i = prev + 1; i <= maxEl + shift; i++) {
            if (line[i] == 0) {
                continue;
            }
            
            if (i - prev == diff) {
                ans.push_back({prev - shift, i - shift});
            } else if (i - prev < diff) {
                diff = i - prev;
                ans = {{prev - shift, i - shift}};
            }
            
            prev = i;
        }
        
        return ans;
    }
};