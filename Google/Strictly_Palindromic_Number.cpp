class Solution {
public:
    bool ChangeBasePal(int n,int b){
        // string s="";
        vector <int> v;
        
        while(n>0){
            v.push_back(n%b);
            n/=b;
        }
        
        int size=v.size();
        for(int i=0;i<size/2;i++){
            if(v[i]!=v[size-i-1])return false;
        }
        return true;
    }
    
    bool isStrictlyPalindromic(int n) {
        for(int b=2;b<=n-2;b++){
            if(!ChangeBasePal(n,b))return false;
        }
        return true;
    }
};