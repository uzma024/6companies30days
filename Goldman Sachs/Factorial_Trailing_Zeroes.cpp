class Solution {
public:
    int trailingZeroes(int n) {
        // trailingZeroes = noof5's
        int i=5;
        int count=0;
        while(i<=n){
            count+=(n/i);
            i*=5;
        }
        return count;
    }
};