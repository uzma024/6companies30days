class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <int> dist(n,1e9);
        dist[src]=0;
        queue <pair<int,int>> q;
        
        vector <vector<pair<int,int> >> adj(n);
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
            // adj[i[1]].push_back(i[0]);
        }
        q.push({src,0});
        
        int stops=0;
        while(!q.empty() && stops<=k){
            int size=q.size();
            while(size--){
                auto [temp,cost] = q.front();
                q.pop();

                for(auto [neighbour, price] :adj[temp]){
                    if(cost + price < dist[neighbour]){
                        dist[neighbour]= cost + price;
                        q.push({neighbour, dist[neighbour]});
                    }
                }
            }
            stops++;
        }
        
        return dist[dst]==1e9?-1:dist[dst];
    }
};