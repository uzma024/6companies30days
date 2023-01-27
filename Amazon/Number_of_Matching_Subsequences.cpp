class Solution {
public:
    bool check(string s1,string s2){
        if(s1.length()<s2.length())return false;
        int i = 0, j = 0;
        while(i<s1.length() && j<s2.length()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return (j==s2.length());
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        map<string,int>m;
        
        for(auto a: words){
            if(m.count(a)){
                ans+= m[a];
            }else{
                ans += m[a] = check(s,a);
            }
        }
        return ans;
    }
};