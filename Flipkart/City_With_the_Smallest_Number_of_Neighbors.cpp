class Solution {
public:
    // Floyd Warshall
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // int n=edges.size();
        vector <vector <int> > v(n,vector<int>(n,1e9));
        
        for(auto e:edges){
            v[e[0]][e[1]]=v[e[1]][e[0]]=e[2];
        }
        for(int i=0;i<n;i++){
            v[i][i]=0;
        }
        
        for(int via=0;via<n;via++){
           for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    v[i][j]=min(v[i][j],v[i][via]+v[via][j]);
                }
            } 
        }
        
        int cities=INT_MAX,ans;
        for(int i=0;i<n;i++){
            int c=0;
            for(auto d:v[i]){
                if(d<=distanceThreshold)c++;
            }
            if(cities>=c)ans = i, cities = c; 
        }
        return ans;
    }
};