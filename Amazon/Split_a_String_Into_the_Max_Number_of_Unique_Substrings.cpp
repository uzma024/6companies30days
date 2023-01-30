class Solution {
public:
    int ans=INT_MIN;
    unordered_set <string> st;
    
    void helper(string s,int count){
        int n=s.length();
        
        if(n==0){
            ans=max(ans,count);
        }
        
        string temp="";
        
        for(int i=0;i<n;i++){
            temp+=s[i];
            if(st.find(temp)!=st.end())continue;
            
            st.insert(temp);
            helper(s.substr(i+1,n),count+1);
            st.erase(temp);
        }
    }
    
    int maxUniqueSplit(string s) {
        helper(s,0);
        return ans;
    } 
};