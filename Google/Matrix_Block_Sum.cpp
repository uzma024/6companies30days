class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n=mat[0].size();
        
        vector <vector<int>> v(m,vector <int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)v[i][j]=mat[i][j];
                else if(i==0)v[i][j]=mat[i][j] + v[i][j-1];
                else if(j==0)v[i][j]=mat[i][j] + v[i-1][j];
                else v[i][j]=mat[i][j] + v[i][j-1] + v[i-1][j] - v[i-1][j-1];
            }
        }
        
        vector <vector<int>> ans(m,vector <int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x1= max(0,i-k);
                int y1= max(0,j-k);
                
                int x2= min(m-1,i+k);
                int y2= min(n-1,j+k);
                
                ans[i][j] = v[x2][y2] - (x1>0? v[x1-1][y2]:0) - (y1>0? v[x2][y1-1]:0) + ((x1>0 && y1>0) ? v[x1-1][y1-1]:0);
            }
        }
        
        return ans;
        
    }
};