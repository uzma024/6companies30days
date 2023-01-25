class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans=0,n=piles.size();
        sort(piles.begin(),piles.end());
        
        int temp=n/3;
        
        // [1,2,2,4,7,8]
        for(int i=n-2;i>=temp;i-=2){
            ans+=piles[i];
        }
        return ans;
    }
};