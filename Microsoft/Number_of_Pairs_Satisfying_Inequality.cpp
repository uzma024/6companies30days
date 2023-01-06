#define ll long long
class Solution {
public:
    
    ll validPairs(int l,int r,vector<int>& nums,int diff){
        if(l==r)return 0;
        
        int m=(l+r)>>1;
        // Divide
        ll ans = validPairs(l,m,nums,diff) + validPairs(m+1,r,nums,diff);
        
        // Merge
        // Valid Pairs in merge
        int l1=l,r1=m,l2=m+1,r2=r;
        
        for(int j=l2;j<=r2;j++){
            ll valid_i=nums[j]+diff;
            
            int ind= upper_bound(nums.begin()+l1,nums.begin()+r1+1,valid_i) - nums.begin() -1;
            if(ind <=r1)ans+= (ind-l1+1);
        }
        
        
        // SORT
        vector <ll> merged;
        while(l1<=r1 && l2<=r2){
            if(nums[l1]<=nums[l2]){
                merged.push_back(nums[l1++]);
            }else{
                merged.push_back(nums[l2++]);
            }
        }
        while(l1<=r1)merged.push_back(nums[l1++]);
        while(l2<=r2)merged.push_back(nums[l2++]);
        
        for(int j=l;j<=r;j++){
            nums[j]=merged[j-l];
        }
        return ans;
    }
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        // (nums1[i] - nums2[i]) + (nums2[j] - nums1[j]) <=  + diff
        int n = nums1.size();
        for(int i=0;i<n;i++){
            nums1[i]-=nums2[i];
        }
        // inequality -> nums1[i] - nums1[j] <= diff
        // Divide and Conquer
        
        return validPairs(0,n-1,nums1,diff);
    }
};

// Time Complexity: O(nlogn)
// Try segment tree or a Fenwick tree 