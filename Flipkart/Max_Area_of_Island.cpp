class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector <int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
        int m=grid.size();
        int n=grid[0].size();
        
        int ans=0;
        
        map <vector <int>, bool> seen;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<i<<" "<<j<<""<<endl; 
                if(grid[i][j]==1 && seen.find({i,j})==seen.end()){
                    queue <vector <int>> q;
                    seen[{i,j}]=true;
                    q.push({i,j});
                    int ar=1;
                    while(!q.empty()){
                        int currX=q.front().at(1);
                        int currY=q.front().at(0);
                        q.pop();
                        cout<<"\nNeightbours"<<endl;
                        for(int k=0;k<directions.size();k++){
                            int y = currY + directions[k][0];
                            int x= currX + directions[k][1];
                            
                            if(y<m && y>=0 && x>=0 && x<n){
                                if(grid[y][x]==1 && seen.find({y,x})==seen.end()){
                                    seen[{y,x}]=true;
                                    // cout<<y<<" "<<x<<endl; 
                                    ar++;
                                    q.push({y,x});
                                }
                            }
                        }
                    }
                    ans=max(ar,ans);
                    // cout<<"ans: "<<ans<<endl;
                    // cout<<endl;
                }
            }
        }
        return ans;
    }
};