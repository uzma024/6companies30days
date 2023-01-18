class Solution {
public:
    
    bool backtrack(vector<int>& nums, int k,int target,vector<int>visited,int i,int currSum){
        if(k==1)return true;
        if(i >= nums.size()) return false;
        if(currSum==target)return backtrack(nums,k-1,target,visited,0,0);
        
        for(int j=i;j<nums.size();j++){
            if(!visited[j] && nums[j] + currSum <= target){
                visited[j]=1;
                if(backtrack(nums,k,target,visited,j+1,currSum+nums[j]))return true;
                visited[j]=0;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size() , sum=accumulate(nums.begin(),nums.end(),0);
        if(n<k || sum%k)return false;
        
        int target=sum/k;
        vector <int> visted(n,0);
        return backtrack(nums,k,target,visted,0,0);
    }
};