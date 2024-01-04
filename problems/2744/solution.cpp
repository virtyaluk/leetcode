class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) { 
        int ans = 0;
        unordered_set<string> us;

        for(string w: words){
            string word = w;
            
            reverse(begin(word), end(word));
            
            if (us.find(w) == end(us)){
                us.insert(word);
            } else {
                ans++;
            }
           
        }

        return ans;
    }
};