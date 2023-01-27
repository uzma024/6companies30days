class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ansF=0,right=0,left=0;
        unordered_map<int, int> mp;
        
        while(right<n){
            if(mp.find(fruits[right])==mp.end()){
                if(mp.size()==2){
                    int ind=right-1, temp=fruits[ind];
                    while(ind>=0){
                        if(fruits[ind]!=temp){
                            mp.erase(fruits[ind]);
                            break;
                        }
                        ind--;
                    }
                    left=ind+1;
                }
                mp[fruits[right]]=1;
            }
            right++;
            ansF=max(ansF,right-left);
        }
        return ansF;
    }
};