class Solution {
public:
    vector <vector <int>> directions={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
    
    
    
    double knightProbability(int n, int k, int row, int column) {
        vector<double>v(n,0);
        vector<vector<double>> currDP(n,v);
        vector<vector<double>> prevDP(n,v);
        
        prevDP[row][column]=1;
        
        for (int i = 1; i < k+1; ++i){
            for (int j = 0; j < n; ++j){
                for (int m = 0; m < n; ++m){
                    double prob=0;
                    for(int d=0;d<8;d++){
                        int x=j+directions[d][0];
                        int y=m+directions[d][1];
                        if(x<0||y<0||x>=n||y>=n){
                            continue;
                        }else{
                            currDP[j][m]+= prevDP[x][y]/8;
                        }

                    }

                }
            }
            prevDP=currDP;
            for (int j = 0; j < n; ++j){
                currDP[j]=v;
            }
            
        }
        
        double ans=0;
        for (int j = 0; j < n; ++j){
            for (int m = 0; m < n; ++m){
                ans+=prevDP[j][m];
            }
        }
        return ans;
    }
};