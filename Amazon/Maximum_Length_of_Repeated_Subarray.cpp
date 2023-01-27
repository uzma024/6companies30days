class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int maximum=0;
        int n=nums1.size();
        int m=nums2.size();
        if(n==0 ||m==0){
            return 0;
        }
        int ans=0;
        int dp[m+1][n+1];
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(j==0 || i==0){
                    dp[i][j]=0;
                }else if(nums1[j-1]==nums2[i-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                     dp[i][j]=0;
                }
                ans=max(ans,dp[i][j]);
            }
            
        }
        return ans;
    }
};