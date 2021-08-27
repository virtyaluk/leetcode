class Solution {
public:
    int overlap(vector<int> &v1, vector<int> &v2, int x, int y) {
	array<int,4> ans={}; 
	int n=v1.size();
	for (int i=0; i<n-x; ++i) {
		ans[0]+=__builtin_popcount((v1[i]>>y)&v2[i+x]);
		ans[1]+=__builtin_popcount(v1[i]&(v2[i+x]>>y));
		ans[2]+=__builtin_popcount((v1[i+x]>>y)&v2[i]);
		ans[3]+=__builtin_popcount(v1[i+x]&(v2[i]>>y));
	}        
	return *max_element(ans.begin(), ans.end());    
}

int largestOverlap(vector<vector<int>>& i1, vector<vector<int>>& i2) {
	int n=i1.size();
	vector<int> v1(n,0), v2(n,0); 
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (i1[i][j]) v1[i]|=1<<j;
			if (i2[i][j]) v2[i]|=1<<j;
		}
	}
	int ans=0;
	for (int i=0; i<n; ++i) 
		for (int j=0; j<n; ++j) 
			ans=max(ans,overlap(v1,v2,i,j));        
	return ans;
}
};