class Solution {
public:
    string tostring(long long n){
        if(n==0)return "0";
        string ans;
        while(n>0){
            string dem;
            dem+=((n%10) + '0');
            ans= dem+ans;
            n/=10;
        }
        return ans;
    }
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)return "0";
        string ans;
        if((numerator>0 && denominator<0)|| (numerator<0 && denominator>0)){
            ans+='-';
        }
        numerator= abs(numerator); 
        denominator= abs(denominator);
        
        long long qoutient=numerator/denominator;
        long long remainder=numerator%denominator;
        ans+=tostring(qoutient);
        
        if(remainder==0){
            return ans;
        }
        ans+='.';
        map<long long,int> mp;
        
        while(remainder!=0){
            if(mp.find(remainder)!=mp.end()){
                int pos=mp[remainder];
                ans.insert(pos,"(");
                ans+=')';
                break;
            }else{
                mp[remainder]=ans.length();
                remainder*=10;
                qoutient=remainder/denominator;
                ans+=tostring(qoutient);
                remainder%=denominator;
            }
        }
        return ans;
    }
};