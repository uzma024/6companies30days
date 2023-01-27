class Solution {
public:
    
    class trie{
        public:
        unordered_map <int,trie*> next;
        int c;
        trie(){
            
        }
        
    };
    
    int countDistinct(vector<int>& nums, int k, int p) {
        int ans=0,n=nums.size();
        
        trie* root=new trie();
        
        for(int i=0;i<n;i++){
            trie*temp =root;
            int count=0;
            
            for(int j=i;j<n;j++){
                if(nums[j]%p==0)count++;
                
                if(count>k)break;
                
                if(!temp->next[nums[j]]){
                    temp->next[nums[j]]=new trie();
                    ans++;
                }
                temp=temp->next[nums[j]];
            }
        }
        return ans;
    }
};