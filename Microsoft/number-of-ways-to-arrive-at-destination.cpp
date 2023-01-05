#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    int MOD = 1e9 + 7;
    int dijkstra(vector <vector<pll >> &lists,int s,int d){
        int n=lists.size();
        vector <ll> dis(d,LONG_MAX);
        vector <ll> ways(d);
        ways[s] = 1;
        dis[s] = 0;

        priority_queue<pll, vector<pll>, greater<>> minHeap;
        
        minHeap.push({0, 0});
        while(!minHeap.empty()){
            auto[d,u]=minHeap.top();
            minHeap.pop();
            if(d>dis[u])continue;

            for(auto [v, cost] :lists[u]){
                if(dis[v] > d+cost){
                    dis[v] = d+cost;
                    ways[v]=ways[u];
                    minHeap.push({dis[v],v});
                }else if(dis[v] == d+cost){
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[d-1];
    }
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector <vector< pll >> lists(n);

        for(auto r: roads){
            ll s = r[0] , d = r[1] , cost = r[2]; 
            lists[s].push_back({d,cost});
            lists[d].push_back({s,cost});
        }

        
        return dijkstra(lists,0,n);
    }
};