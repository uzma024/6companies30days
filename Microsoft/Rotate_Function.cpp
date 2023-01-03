class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);

        int first=0,j=0,n=nums.size();
        for(auto k:nums){
            first+=(j*k);
            j++;
        }
        
        int ans=first;
        for(int i=0;i<n;i++){
            first+=(sum-n*nums[n-1-i]);
            ans=max(first,ans);
        }
        return ans;
    }
};