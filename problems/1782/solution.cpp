class Solution {
public:
    #define pii pair<int,int>
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        
        //O(N)
        //Degree Calculation
        vector<int> degree(n,0);
        for(vector<int> &edge : edges)
        {
            degree[edge[0]-1]++;
            degree[edge[1]-1]++;
        }
        
        //O(N)
        //Build Adjacency List Keeping Count of Repeated Children
        vector<unordered_map<int,int>> adjChildCount(n,unordered_map<int,int>());
        for(vector<int> &edge : edges)
        {
            int u = edge[0]-1, v = edge[1]-1;
            adjChildCount[u][v]++;
            adjChildCount[v][u]++;
        }
        
        //O(E*logN)
        //Determine Number of Phony Children per Node for range of values
        vector<map<int,int>> adjDegCount(n,map<int,int>());
        for(int node = 0;node<n;node++)
        {
            for(const pii &neigh : adjChildCount[node])
            {
                int child = neigh.first;
                int count = neigh.second;
                int deg = degree[child];
                adjDegCount[node][deg+1]--;
                adjDegCount[node][deg-count+1]++;
            }
        }
        
        int runSum = 0;
        for(int node = 0;node<n;node++)
        {
            for(const pii &elem : adjDegCount[node])
            {
                runSum+=elem.second;
                adjDegCount[node][elem.first] = runSum;
            }
            adjDegCount[node][INT_MIN] = 0;//To Prevent Index Not Found while upper_bound()-1
        }
        
        //O(N*logN)
        //Store Sorted Degree List
        vector<int> degList;
        for(int node = 0;node<n;node++)
            degList.push_back(degree[node]);
        sort(degList.begin(),degList.end());
        
        //O(Q*N*logN)
        //Answer Queries
        vector<int> ans;
        for(int &query : queries)
        {
            int currAns = 0;
            for(int node = 0;node<n;node++)
            {
                int currDegree = degree[node];
                int remaining = query+1-currDegree;
                int pos = lower_bound(degList.begin(),degList.end(),remaining)
                    -degList.begin();
                int count = n-pos;
                int phony = (--adjDegCount[node].upper_bound(remaining))->second;
                count-=phony;
                count-=(currDegree>=remaining);
                currAns+=count;
            }
            currAns/=2;
            ans.push_back(currAns);
        }
        return ans;
    }
};