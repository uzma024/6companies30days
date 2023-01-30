class Solution {
public:
    
    
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n=creators.size();
        map <string , long long> m;
        map <string , vector<pair<string,long long>>> ans;
        
        long long ma=0;
        
        for(int i=0;i<n;i++){
            m[creators[i]]+=views[i];
            ma = max(ma,m[creators[i]]);
            ans[creators[i]].push_back({ids[i],views[i]});
        }
        
        vector<vector<string>> res;
        for (auto i:m){
            if(i.second==ma){
                auto [s_temp,num_temp] =ans[i.first][0];
                
                for(auto j : ans[i.first]){
                    if(j.second>num_temp){
                        s_temp=j.first;
                        num_temp=j.second;
                    }else if(j.second == num_temp && s_temp>j.first){
                        s_temp=j.first;
                    }
                }
                res.push_back({i.first,s_temp});
            }
        }
        return res;
    }
};