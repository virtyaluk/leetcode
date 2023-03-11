#define ll long long

class Solution {
public:
    long long totalCost(vector<int>& v, int k, int candidates) {
        int n=v.size();
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int l=candidates-1,r=n;
        for(int i=0;i<candidates;i++){
            pq.push({v[i],i});
        }

        for(int i=n-1;i>l && (n-1-i)<candidates;i--){
            pq.push({v[i],i});
            r=i;
        }
        // cout<<l<<" "<<r<<endl;
        ll ans=0;
        while(k){
            ans+=pq.top().first;
            int idx=pq.top().second;
            pq.pop();

            if(l+1<r){
                if(idx<=l){
                    l++;
                    pq.push({v[l],l});
                }

                else{
                    r--;
                    pq.push({v[r],r});
                }
            }

            k--;
        }

        return ans;
    }
};