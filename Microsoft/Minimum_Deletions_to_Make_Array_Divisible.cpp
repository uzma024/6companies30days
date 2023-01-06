class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            // cout<<nums[i]<<" ";
            if(nums[i]==0)continue;
            bool flag=true;
            for(auto j:numsDivide){
                if(j%nums[i]!=0){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return i;
            }else{
                while(i+1<n && nums[i+1]==nums[i]){
                    i++;
                }
            }
        }
        return -1;
    }
};

// Brute force ⬆️
// can be improved!!