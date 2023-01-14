class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a=INT_MAX,b=INT_MAX;
        for(auto i:nums){
            if(i>b)return true;
            if(i>a)b=min(b,i);
            a=min(i,a);
        }
        return false;
    }
};