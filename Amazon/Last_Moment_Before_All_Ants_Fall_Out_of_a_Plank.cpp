class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int k=left.size(), m=right.size();
        
        if(k)sort(left.begin(),left.end());
        if(m)sort(right.begin(),right.end());
        
        if(!k && !m)return -1;
        if(!m)return left.back();
        if(!k)return n - right[0];
        
        return max(left.back(),n - right[0]);
    }
};