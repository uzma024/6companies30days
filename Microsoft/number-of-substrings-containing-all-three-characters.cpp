class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0,n=s.length();
        int i=0,j=0;
        
        int c_a=0,c_b=0,c_c=0;
        
        while(i<n && j<n){
            if(s[j]=='a')c_a++;
            else if(s[j]=='b')c_b++;
            else if(s[j]=='c')c_c++;
            
            while(c_a>0 && c_b>0 && c_c>0){
                count+=(n-j);
                if(s[i]=='a')c_a--;
                else if(s[i]=='b')c_b--;
                else if(s[i]=='c')c_c--;
                
                i++;
            }
            j++;
        }
        return count;
    }
};