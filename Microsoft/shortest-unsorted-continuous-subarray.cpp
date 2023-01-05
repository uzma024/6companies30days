class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int first=-1,last=-1;
        int max=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            if(max>nums[i]){
                if(first==-1){
                    first=i-1;
                }
                while(first-1>=0 && nums[first-1]>nums[i]){
                    first--;
                }
                last=i+1;
            }else{
                max=nums[i];
            }
        }
        return last-first;
    }
};