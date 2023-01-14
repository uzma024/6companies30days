class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector <int>maxFromLast(n);
        int maxi=INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxi=max(nums[i],maxi);
            maxFromLast[i]=maxi;
        }
        int minI=0;
        for(int i=0;i<n-1;i++){
            if(nums[minI]>nums[i])minI=i;
            if(nums[minI]<nums[i] && nums[i]<maxFromLast[i+1]){
                return true;
            }
        }
        return false;
    }
};