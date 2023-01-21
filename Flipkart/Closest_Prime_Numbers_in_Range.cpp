class Solution {
public:
    vector <bool> prime;
    void sieveOfEratosthenes(int n){
        for(int i=2;i*i<n;i++){
            if(prime[i]){
                for(int j=i*i;j<n;j+=i){
                    prime[j]=false;
                }
            }
        }
    }
    
    
    vector<int> closestPrimes(int left, int right) {
        prime.resize(right+1,1);
        sieveOfEratosthenes(right+1);
        prime[0]=0;
        prime[1]=0;
        vector <int> v(2,-1);
        
        int prev=-1,ans=INT_MAX;
        
        for(int i=left;i<=right;i++){
            if(prime[i]){
                if(prev==-1){
                    prev=i;
                }else{
                    if(i-prev<ans){
                        v[0]=prev;
                        v[1]=i;
                        ans=i-prev;
                    }
                }
                prev=i;
            }
        }
        return v;
    }
};