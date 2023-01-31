class Solution {
public:
    long long mod = 1e9 + 7;
    
    int rev(int n){
        int ans=0;
        while(n>0){
            ans = ans*10 + n%10;
            n/=10;
        }
        return ans;
    }
    
    int countNicePairs(vector<int>& nums) {
        map <int,long> m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i] - rev(nums[i])]++;
        }
        long long ans=0;
        for(auto i:m){
            // cout<<i.first<<" "<<i.second<<endl;
            ans += ((i.second * (i.second -1)) / 2);
            ans%=mod;
        }
        
        return ans%mod;
    }
};