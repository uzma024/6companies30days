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
                m1[secret[i]]++;
                m2[guess[i]]++;
            }
        }

        for(auto i:m1){
            char ch=i.first;
            // cout<<ch<<" : "<<m1[c]<<","<<m2[c]<<endl;
            if(m2.find(ch)!=m2.end()){
                c+=min(m1[ch],m2[ch]);
            }
        }
        
        string s="";
        s=to_string(b)+"A"+to_string(c)+"B";

        return s;
    }
};