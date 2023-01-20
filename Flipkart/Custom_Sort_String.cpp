class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>m;
        
        for(auto i: s){
            m[i]++;
        }
        
        string ans="";
        
        for(auto i:order){
            if(m.find(i)!=m.end()){
                while(m[i]>0){
                    ans+=i;
                    m[i]--;
                }
            }
        }
        
        for(auto i:m){
            int n=i.second;
            char c=i.first;
            while(n--){
                ans+=c;
            }
        }
        
        return ans;
    }
};