class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        vector <int>lps(n,0);
        int prevLPS=0,i=1;
        while(i<n){
            if(s[i]==s[prevLPS]){
                lps[i]=prevLPS+1;
                prevLPS++;
                i++;
            }else{
                if(prevLPS==0){
                    lps[i]=0;
                    i++;
                }else{
                    prevLPS=lps[prevLPS-1];
                }
            }
        }
        
        return s.substr(0,lps[n-1]);
    }
};