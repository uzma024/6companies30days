class Solution {
public:
    int dp[4001][1001] = {}, mod = 1000000007;
    
    int helper(int currVertex,int target,int k){
        if(k==0){
            if(currVertex==target)return 1;
            return 0;
        }
        
        if(dp[currVertex+1000][k]!=-1)return dp[currVertex+1000][k];
        
        long long ans = helper(currVertex+1,target,k-1) + helper(currVertex-1,target,k-1);
        
        return dp[currVertex+1000][k] = ans%mod;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        for(int i=0;i<=3001;i++){
            for(int j=0;j<=k;j++){
                dp[i][j]=-1;
            }
        }
        
        long long ans = helper(startPos,endPos,k);
        return ans%mod;
    }
};