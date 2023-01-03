class Solution {
public:
    string getHint(string secret, string guess) {
        
        int b=0,c=0,n=secret.length();

        map <char,int>m1;
        map <char,int>m2;
        
        for(int i=0;i<n;i++){
            if(guess[i]==secret[i]){
                b++;
            }else{
                m1[guess[i]]++;
                m2[secret[i]]++;
            }
        }

        for(auto i:m1){
            char c=i.first;
            if(m2.find(c)!=m2.end()){
                c+=min(m1[c],m2[c]);
            }
        }
        
        string s="";
        s+=('0'+b);
        s+='A';
        s+=('0'+c);
        s+='B';

        return s;
    }
};