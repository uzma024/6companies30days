class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // y=mx+c
        // m,c pairs
        
        int n=points.size();
        if(n<3)return n;
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<double,int> mp;
            double x1=points[i][0],y1=points[i][1];
            for(int j=i+1;j<n;j++){
                double x2=points[j][0],y2=points[j][1];
                double m;
                if(x2 - x1==0){
                    m=INT_MAX;
                }else{
                    m=(y2 - y1)/(x2 - x1);
                }
                mp[m]++;
                ans=max(ans,mp[m]);
            }
        }
        
        return ans+1;
    }
};