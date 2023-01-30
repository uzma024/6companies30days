class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        
        int mod = 1000000007;
        
        stack <pair<int,int>> st;
        int n=nums.size();
        long long ans=0;
        
        vector <long long> pref(n+1);
        pref[0]=0;
        for(int i=1;i<=n;i++){
            pref[i] = (pref[i-1] + nums[i-1]);
        }
        
        for(int i=0;i<n;i++){
            
            int newStart=i;
            while(!st.empty() && st.top().second>nums[i]){
                auto [start,val] = st.top();
                st.pop();
                ans=max(ans,val * (pref[i] - pref[start]));
                newStart = start;
            }
            
            st.push({newStart,nums[i]});
        }
        
        while(!st.empty()){
            auto [start,val] = st.top();
            st.pop();
            ans=max(ans,val * (pref[n] - pref[start]));
        }
        
        return ans%mod;
    }
};