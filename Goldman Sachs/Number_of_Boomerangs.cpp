class Solution {
public:
    long long dist(vector<int>&p1 , vector<int> &p2){
        int a=p1[0]-p2[0] ,b=p1[1] - p2[1];
        return a*a +b*b;
    }
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        // map <long long,int> m;
        int n=points.size();
        
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map <long long, int> m;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                long long d=dist(points[i],points[j]);
                m[d]++;
            }
            for(auto i:m){
                int k=i.second;
                if(k < 2) continue;
                ans+=(k*(k-1));
            }
        }
        
        
        return ans;
    }
};