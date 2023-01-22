class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int iterations=n-1;
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i]=INT_MAX;
        }
        arr[k-1]=0;
        
        while(iterations>0){
            int count=0;
            for(int i=0;i<times.size();i++){
                int source=times[i][0]-1;
                int target=times[i][1]-1;
                int time=times[i][2];
                if(arr[source]!=INT_MAX && arr[source]+time<arr[target]){
                    arr[target]=arr[source]+time;
                    count++;
                }
            }
            if(count==0){
                break;
            }
            iterations--;
        }
        int ans=0;
        
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
            if(arr[i]==INT_MAX){
                return -1;
            }else{
                ans=max(ans,arr[i]);
            }
        }
        return ans;
    }
};