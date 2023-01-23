class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n=statements.size();
        
        int ans=0;
        for(int i=1;i< (1<<n);i++){
            int chk=1;
            for(int j=0;j<n;j++){
                if(!(i&(1<<j)))continue;
                for(int k=0;k<n;k++){
                    if( i&(1<<k) && statements[j][k]==0){
                        chk=-1;
                        break;
                    }
                    if( !(i&(1<<k)) && statements[j][k]==1){
                        chk=-1;
                        break;
                    }
                }
                if(chk==-1)break;
            }
            if(chk==1){
                int c=0;
                int num=i;
                while(num>0){
                    if(1&num){c++;}
                    num=num>>1;
                }
                ans=max(ans,c);
            }
            
        }
        return ans;
    }
};